#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([libprom libpromhttp], [1.0.0], [rochermankind@163.com])
#AC_INIT([libpromhttp],[1.0],[rochermankind@163.com])
AM_INIT_AUTOMAKE([-Wall -Werror foreign])
AC_CONFIG_SRCDIR([prom/include/prom_collector_registry.h])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_MACRO_DIRS([m4])
AC_SUBST([LIBPROM_SO_VERSION],[1:0:0])
AC_SUBST([LIBPROMHTTP_SO_VERSION],[1:0:0])

# Checks for programs.
AC_PROG_AWK
AC_PROG_CC
AC_PROG_CXX
AM_PROG_AR([ar])

# Checks for libraries.
AC_PROG_LIBTOOL

# Checks for header files.
AC_CHECK_HEADERS([fcntl.h limits.h stddef.h stdint.h stdlib.h string.h sys/time.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_CHECK_HEADER_STDBOOL
AC_TYPE_PID_T
AC_TYPE_SIZE_T
AC_TYPE_SSIZE_T
AC_TYPE_UINT32_T
AC_TYPE_UINT64_T

# Checks for library functions.
AC_FUNC_MALLOC
AC_FUNC_REALLOC
AC_FUNC_STRTOD
AC_CHECK_FUNCS([clock_gettime memmove memset putenv regcomp strchr strdup strstr strtoul sysinfo])

AC_CONFIG_FILES([Makefile
                 prom/Makefile
				 promhttp/Makefile])
AC_OUTPUT
