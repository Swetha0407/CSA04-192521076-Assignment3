#!/bin/bash
set -e;cd "$(dirname "$0")";mkdir -p outputs;gcc -std=c11 -Wall -Wextra paging.c -o paging;./paging | tee outputs/paging.txt;/usr/bin/time -v ./paging > outputs/time.txt 2>&1;python3 experiment.py
