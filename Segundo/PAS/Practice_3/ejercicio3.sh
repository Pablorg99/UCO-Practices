#!/bin/bash

# If the number of arguments is not correct, print error message and exit the script
if [ $# -lt 1 ] || [ $# -gt 3 ]; then
	echo "El uso correcto es: $ ejercicio3.sh <directorio> [umbral_bytes1] [umbral_bytes2]"
	exit 1
fi

# Set default values for optional arguments
umbral1=10000
umbral2=100000

# Change those values if arguments are specified by the user

if [ $# -gt 1 ] && [ "$2" -ne 0 ]; then
	umbral1=$2
fi

if [ $# -gt 2 ] && [ "$3" -ne 0 ]; then
	umbral1=$3
fi

# Swap "umbral1" and "umbral2" if the user put them wrongly
if [ $umbral1 -ge $umbral2 ]; then
	aux=$umbral2
	umbral2=$umbral1
	umbral1=$aux
fi

# If folders existed previously, removed them and create them again
# If they didn't exist previuosly, just create them
if [[ -d "pequenos" && "medianos" && "grandes" ]]; then
	rm -rf pequenos medianos grandes
	mkdir pequenos medianos grandes
	echo "Las carpetas de salida ya existen, se va a proceder a borrarlas..."
else
	echo "Creando las carpetas pequenos, medianos y grandes"
	mkdir pequenos medianos grandes
fi

echo "Copiando los archivos..."

# Ficheros pequeños
for file in $(find $1 -size -"$umbral1"c -type f -or -size "$umbral1"c -type f)
do
	cp $file pequenos
done

# Ficheros medianos
for file in $(find $1 -size +"$umbral1"c -type f -and -size -"$umbral2"c -type f)
do
	cp $file medianos
done

# Ficheros grandes
for file in $(find $1 -size +"$umbral2"c -type f -or -size "$umbral2"c -type f)
do
	cp $file grandes
done
