#!/bin/bash
set -u;cd "$(dirname "$0")";mkdir -p outputs;gcc -std=c11 -Wall -Wextra segment.c -o segment;./segment > outputs/segment.txt;gcc -std=c11 -Wall -Wextra segfault.c -o segfault;(ulimit -c 0;./segfault) > outputs/segfault.txt 2>&1 || true
