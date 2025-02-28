libprom
=======
This repo is a fork of the [Prometheus client libraries for C](https://github.com/digitalocean/prometheus-client-c) repository.
Base on []
It provides shared libraries for instrumenting software and exposing metrics in text format as defined by the Prometheus exposition format (see https://prometheus.io/docs/instrumenting/exposition_formats/ for more details). libprom provides the core API implementation, libpromhttp a simple web handler to expose metrics for scraping.

Improvements wrt. to the forked source:
---------------------------------------
- now many bugs and tests fixed!


Build, Install, Test
--------------------
Just new a few commands to make your own library
```shell
./configure
make 
make install
``` 

Branch info
-----------
The **master** branch is used to track the main development branch of the upstream repo, the **main** branch is the main development branch of this repo.
