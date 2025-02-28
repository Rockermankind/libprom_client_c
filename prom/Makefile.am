libprom_CFLAGS="-Werror" "-Wuninitialized" "-Wall" "-Wno-unused-label" "-std=gnu11"
lib_LTLIBRARIES = libprom.la
AUTOMAKE_OPTIONS=subdir-objects
libprom_la_LDFLAGS = -version-info $(LIBPROM_SO_VERSION)
libprom_la_SOURCES = src/prom_assert.h     \
                     src/prom_collector.c      \
                     src/prom_collector_registry.c     \
                     src/prom_collector_registry_i.h       \
                     src/prom_collector_registry_t.h       \
                     src/prom_collector_t.h        \
                     src/prom_counter.c        \
                     src/prom_gauge.c      \
                     src/prom_histogram.c      \
                     src/prom_histogram_buckets.c      \
                     src/prom_linked_list.c        \
                     src/prom_linked_list_i.h      \
                     src/prom_linked_list_t.h      \
                     src/prom_log.c        \
                     src/prom_map.c        \
                     src/prom_map_i.h      \
                     src/prom_map_t.h      \
                     src/prom_metric.c     \
                     src/prom_metric_formatter.c       \
                     src/prom_metric_formatter_i.h     \
                     src/prom_metric_formatter_t.h     \
                     src/prom_metric_i.h       \
                     src/prom_metric_sample.c      \
                     src/prom_metric_sample_histogram.c        \
                     src/prom_metric_sample_histogram_i.h      \
                     src/prom_metric_sample_histogram_t.h      \
                     src/prom_metric_sample_i.h                \
                     src/prom_metric_sample_t.h                \
                     src/prom_metric_t.h               \
                     src/prom_process_collector_t.h                \
                     src/prom_process_collector.c              \
                     src/prom_process_fds.c                \
                     src/prom_process_fds_i.h              \
                     src/prom_process_limits.c             \
                     src/prom_process_limits_i.h               \
                     src/prom_process_stat.c               \
                     src/prom_process_stat_i.h             \
                     src/prom_process_stat_t.h             \
                     src/prom_string_builder.c             

AM_CPPFLAGS = -I./include/

include_HEADERS =    include/prom_alloc.h              \
                     include/prom_collector.h              \
                     include/prom_collector_registry.h             \
                     include/prom_counter.h                \
                     include/prom_gauge.h              \
                     include/prom_histogram.h              \
                     include/prom_histogram_buckets.h              \
                     include/prom_linked_list.h                \
                     include/prom_log.h                \
                     include/prom_map.h                \
                     include/prom_metric.h             \
                     include/prom_metric_sample.h              \
                     include/prom_metric_sample_histogram.h                \
                     include/prom_string_builder.h         \
                     include/prom.h

        
