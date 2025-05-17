#!/bin/bash
sed 's/[[:space:]]\+/\n/g' words.txt | grep -v '^$' | sort | uniq -c | sort -nr | awk '{print $2, $1}'
