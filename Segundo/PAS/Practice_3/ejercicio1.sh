#!/bin/bash

if [ $# != 1 ]; then
	echo "Indique un directorio sobre el que buscar"
else
	dotc_files=$(find $1 -name "*.c" | wc -l)
	doth_files=$(find $1 -name "*.h" | wc -l)
	echo "Tenemos $dotc_files ficheros con extensión .c y $doth_files ficheros con extensión .h"
	for file in $(find $1 -type f -name "*.c" -or -type f -name "*.h") 
	do
		n_lines=$(wc -l < $file)
		n_chars=$(wc -m < $file)
		echo "El fichero $file tiene $n_lines líneas y $n_chars caracteres" 
	done | sort -nr -k 8
fi

