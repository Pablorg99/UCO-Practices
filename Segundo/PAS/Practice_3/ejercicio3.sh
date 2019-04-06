#!/bin/bash
# arg1: carpeta
# arg2: umbral1 (opcional)
# arg3: umbral2 (opcional)

# mkdir pequeños
# mkdir medianos
# mkdir grandes

for $file in $(find $1 -size +$2 -type f) # pequeños
do
	cp $file pequeños #...
done

