#!/bin/bash

if [ $# -lt 1 ] || [ $# -gt 2 ]; then
	echo "La ejecución correcta es: $ ejercicio2.sh <directorio> [numero_bytes]"
fi

if [ $# -eq 2 ]; then
	n_bytes=$2
else 
	n_bytes=0
fi

echo "Nombre LongitudUsuario FechaModificacion FechaAcceso Tamaño Bloques Permisos Ejecutable"
for file in $(find $1 -size +"$n_bytes"c -type f -or -size "$n_bytes"c -type f)
do
	LongitudUsuario=$(stat -c %U $file | wc -m)

	if [[ -x "$file" ]]
	then
		Ejecutable=1
	else
		Ejecutable=0
	fi

	echo "$(basename $file);$LongitudUsuario;$(stat -c '%y;%X;%s;%b;%A' $file);$Ejecutable)"
done | sort -k 5 -n -t ";"
