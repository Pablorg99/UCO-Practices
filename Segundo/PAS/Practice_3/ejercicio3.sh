#!/bin/bash

# Comprueba el uso adecuado del script
if [ $# -lt 1 ] || [ $# -gt 3 ]; then
	echo "El uso correcto es: $ ejercicio3.sh <directorio> [umbral_bytes1] [umbral_bytes2]"
	exit 1
fi

# Cambia los valores por defecto si se indica y son correctos
if [ $# -eq 3 ]; then
	if [ $2 -lt $3 ]; then
		umbral1=$2
		umbral2=$3
	else
		echo "El umbral1 introducido es mayor o igual que el umbral2 de manera que se usaran los valores por defecto"
		umbral1=10000 	
		umbral2=100000
	fi
else
	umbral1=10000
	umbral2=100000
fi

# 
if [ ! -d "pequeños" ]; then
	mkdir pequeños
fi

if [ ! -d "medianos" ]; then
	mkdir medianos
fi

if [ ! -d "grandes" ]; then
	mkdir grandes
fi

# Ficheros pequeños
for file in $(find $1 -size -"$umbral1"c -type f -or -size "$umbral1"c -type f)
do
	cp $file pequeños
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
