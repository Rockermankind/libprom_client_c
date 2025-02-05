/**
 * Copyright 2019-2020 DigitalOcean Inc.
 * Copyright 2021 Jens Elkner <jel+libprom@cs.uni-magdeburg.de>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "prom_test_helpers.h"

void
test_prom_histogram(void) {
	phb_t *bucket = phb_linear(5.0, 5.0, 3);
	prom_histogram_t *h = prom_histogram_new("test_histogram",
		"histogram under test", bucket, 0, NULL);

	prom_histogram_observe(h, 1.0, NULL);
	prom_histogram_observe(h, 7.0, NULL);
	prom_histogram_observe(h, 11.0, NULL);
	prom_histogram_observe(h, 22.0, NULL);

	pms_histogram_t *h_sample = pms_histogram_from_labels(h, NULL);

	// Test counter for each bucket
	const char *bucket_key = bucket->key[0];
	const char *l_value = prom_map_get(h_sample->l_values, bucket_key);
	pms_t *sample = (pms_t *) prom_map_get(h_sample->samples, l_value);
	TEST_ASSERT_EQUAL_STRING("test_histogram_bucket{le=\"5.0\"}", sample->l_value);
	TEST_ASSERT_EQUAL_DOUBLE(1.0, sample->r_value);
	bucket_key = NULL;

	bucket_key = bucket->key[1];
	l_value = prom_map_get(h_sample->l_values, bucket_key);
	sample = (pms_t *) prom_map_get(h_sample->samples, l_value);
	TEST_ASSERT_EQUAL_STRING("test_histogram_bucket{le=\"10.0\"}", sample->l_value);
	TEST_ASSERT_EQUAL_DOUBLE(2.0, sample->r_value);
	bucket_key = NULL;

	bucket_key = bucket->key[2];
	l_value = prom_map_get(h_sample->l_values, bucket_key);
	sample = (pms_t *) prom_map_get(h_sample->samples, l_value);
	TEST_ASSERT_EQUAL_STRING("test_histogram_bucket{le=\"15.0\"}", sample->l_value);
	TEST_ASSERT_EQUAL_DOUBLE(3.0, sample->r_value);
	bucket_key = NULL;

	l_value = prom_map_get(h_sample->l_values, "+Inf");
	sample = (pms_t *) prom_map_get(h_sample->samples, l_value);
	TEST_ASSERT_EQUAL_STRING("test_histogram_bucket{le=\"+Inf\"}", sample->l_value);
	TEST_ASSERT_EQUAL_DOUBLE(4.0, sample->r_value);

	// Test total count. Should equal value ini +Inf
	l_value = prom_map_get(h_sample->l_values, "count");
	pms_t *sample_count = (pms_t *) prom_map_get(h_sample->samples, l_value);
	TEST_ASSERT_EQUAL_STRING("test_histogram_count", sample_count->l_value);
	TEST_ASSERT_EQUAL_DOUBLE(4.0, sample_count->r_value);

	// Test sum
	l_value = prom_map_get(h_sample->l_values, "sum");
	sample = (pms_t *) prom_map_get(h_sample->samples, l_value);
	TEST_ASSERT_EQUAL_STRING("test_histogram_sum", sample->l_value);
	TEST_ASSERT_EQUAL_DOUBLE(41.0, sample->r_value);

	prom_histogram_destroy(h);
	h = NULL;
}

int
main(int argc, const char **argv) {
	UNITY_BEGIN();
	RUN_TEST(test_prom_histogram);
	return UNITY_END();
}
