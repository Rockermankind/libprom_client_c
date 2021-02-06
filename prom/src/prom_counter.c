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

// Public
#include "prom_counter.h"

#include "prom_alloc.h"

// Private
#include "prom_assert.h"
#include "prom_errors.h"
#include "prom_log.h"
#include "prom_metric_i.h"
#include "prom_metric_sample_i.h"
#include "prom_metric_sample_t.h"
#include "prom_metric_t.h"

prom_counter_t *
prom_counter_new(const char *name, const char *help, size_t label_key_count,
	const char **label_keys)
{
	return (prom_counter_t *)
		prom_metric_new(PROM_COUNTER, name, help, label_key_count, label_keys);
}

int
prom_counter_destroy(prom_counter_t *self) {
	return (self == NULL) ? 0 : prom_metric_destroy(self);
}

int
prom_counter_inc(prom_counter_t *self, const char **label_vals) {
	if (self == NULL)
		return 1;
	if (self->type != PROM_COUNTER) {
		PROM_WARN(PROM_METRIC_INCORRECT_TYPE " (%d)", self->type);
		return 1;
	}
	pms_t *s = pms_from_labels(self, label_vals);
	return (s == NULL) ? 1 : pms_add(s, 1.0);
}

int
prom_counter_add(prom_counter_t *self, double r_value, const char **label_vals)
{
	if (self == NULL)
		return 1;
	if (self->type != PROM_COUNTER) {
		PROM_WARN(PROM_METRIC_INCORRECT_TYPE " (%d)", self->type);
		return 1;
	}
	pms_t *s = pms_from_labels(self, label_vals);
	return (s == NULL) ? 1 : pms_add(s, r_value);
}

int
prom_counter_reset(prom_counter_t *self, double r_value, const char **label_vals) {
	if (self == NULL)
		return 1;
	if (self->type != PROM_COUNTER) {
		PROM_WARN(PROM_METRIC_INCORRECT_TYPE " (%d)", self->type);
		return 1;
	}
	pms_t *s = pms_from_labels(self, label_vals);
	return (s == NULL) ? 1 : pms_set(s, r_value);	// pms_set handles vals < 0
}
