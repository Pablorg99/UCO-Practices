#!/bin/bash

if [[ $# -ne 1 || ! -f $1 ]]; then
	echo "La ejecución correcta del programa es: ejercicio2.sh <rutaFichero.txt>"
	exit 1
fi

grep -E '^.+[^=+]$' peliculas.txt | sed -r 
'
	
'  
