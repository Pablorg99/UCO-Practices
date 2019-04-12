#!/bin/bash

# Number of directories in current path
nDirectories=$(find . -maxdepth 1 -type f | wc -l)
echo "El numero de ficheros en el directorio actual es $nDirectories"

# Awk prints the parameter passed to it (output of who), this second output is sorted and repeated elements are deleted
echo $(who | awk '{print $1}' | sort | uniq)

# If there isn't any input on read command within 5 seconds, $char is empty so is assigned to 'a' in the if sentence"
echo -n "¿Qué carácter quieres contar? "
read -n 1 -t 5 char
if [ "$char" == "" ]; then
	char="a"
fi

# Loops printing the basename of each file and looking for $char, every coincidence is counted by wc and stored in 'fichero.temp'
for file in $(find .)
do 
	echo "$(basename $file)"
done | grep "$char" -o | wc -l > fichero.temp
echo -e "\nEl carácter $char aparece $(cat fichero.temp) veces en nombres de ficheros o carpetas contenidos en la carpeta actual"
rm -f fichero.temp
