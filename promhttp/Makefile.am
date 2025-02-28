libpromhttp_CFLAGS="-Werror" "-Wuninitialized" "-Wall" "-Wno-unused-label" "-std=gnu11"
lib_LTLIBRARIES = libpromhttp.la
AUTOMAKE_OPTIONS=subdir-objects
libpromhttp_la_LDFLAGS = -version-info $(LIBPROMHTTP_SO_VERSION)
libpromhttp_la_SOURCES = src/promhttp.c

AM_CPPFLAGS = -I./include/ \
				-I../prom/include/

include_HEADERS = include/promhttp.h
