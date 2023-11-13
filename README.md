libprom
=======
This repo is a fork of the [Prometheus client libraries for C](https://github.com/digitalocean/prometheus-client-c) repository.

It provides shared libraries for instrumenting software and exposing metrics in text format as defined by the Prometheus exposition format (see https://prometheus.io/docs/instrumenting/exposition_formats/ for more details). libprom provides the core API implementation, libpromhttp a simple web handler to expose metrics for scraping.

Improvements wrt. to the forked source:
---------------------------------------
- bug and test fixes
- much less useless bloat
- compact function and type names, reduced code dups
- better performance
- enhanced and re-usable logging
- better documentation
- better process metrics about the collector itself incl. scrapetimes
- compact output, i.e. option that allows to supress the huge
  `# HELP` and `# TYPE` overhead in prometheus formatted output
- has now a `prom_counter_reset()` function
- `prom_string_builder()` is now public, i.e. usable by libprom consumers
- improved/KISSed process limit scraping (10..200x faster)
- libprom's process_collector is enhanced and now public, i.e. can now be used
  by libprom consumers to collect metrics of other processes easily
- new functions `prom_collector_data_set()` and `prom_collector_data_get()`
  allow to attach custom data by reference to every collector as well as read
  them back
- Solaris/Smartos/OmniOS/Illumos support


Branch info
-----------
The **master** branch is used to track the main development branch of the upstream repo, the **main** branch is the main development branch of this repo.
