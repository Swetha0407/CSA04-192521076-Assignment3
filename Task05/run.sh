#!/bin/bash
set -e;cd "$(dirname "$0")";mkdir -p outputs;gcc -std=c11 -Wall -Wextra replacement.c -o replacement;./replacement | tee outputs/reference_results.txt;python3 experiment.py
