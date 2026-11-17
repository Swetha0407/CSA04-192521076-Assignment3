#!/bin/bash
set -e;cd "$(dirname "$0")";mkdir -p outputs;gcc -std=c11 -Wall -Wextra memory_touch.c -o memory_touch;gcc -std=c11 -Wall -Wextra cow.c -o cow;./memory_touch 128 | tee outputs/memory_touch.txt;./cow | tee outputs/cow.txt;
