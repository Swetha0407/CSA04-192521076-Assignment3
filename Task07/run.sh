#!/bin/bash
set -e;cd "$(dirname "$0")";mkdir -p outputs;gcc -std=c11 -Wall -Wextra locked_loop.c -o locked_loop;./locked_loop | tee outputs/locked_loop.txt;python3 memory_plan.py
