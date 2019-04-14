#!/bin/bash

# Exit script if the number of arguments is not correct or the argument passed is not a directory
if [ $# != 1 ] && [ ! -d "$1" ]; then
	echo "Indique un directorio sobre el que buscar"
	exit 1
else
	dotc_files=$(find $1 -name "*.c" | wc -l)
	doth_files=$(find $1 -name "*.h" | wc -l)
	echo "Tenemos $dotc_files ficheros con extensión .c y $doth_files ficheros con extensión .h"
	for file in $(find $1 -type f -name "*.c" -or -type f -name "*.h") 
	do
		# Doing "< $file" makes wc to get only the option specified, without the filename
		n_lines=$(wc -l < $file)
		n_chars=$(wc -m < $file)
		echo "El fichero $file tiene $n_lines líneas y $n_chars caracteres" 
	# "-k 8" because the number of chars is the 8th word of the string echoed
	done | sort -nr -k 8
fi

