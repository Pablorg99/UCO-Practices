#!/bin/bash
echo $(who | awk '{print $1}' | sort | uniq)
# read -> char
for $file in $(find)
do 
	echo "$(basename $file)"
done | grep $char -o | wc -l
