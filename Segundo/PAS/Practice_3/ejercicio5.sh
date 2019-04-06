#!/bin/bash
# ficheros $* 
date=$(date +%s)
for $file in $(find copiaseg -type f)
do
	creation=$(stat $file -c %x)
	time=$date-$creation
done
tar -cfx copiaseg/copia-$(whioami)-$date.tar.g $* 
