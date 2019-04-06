#!/bin/bash


if [ $# -lt 1 ] || [ $# -gt 2 ]; then
	echo "La ejecución correcta es: $ ejercicio2.sh <directorio> [numero_bytes]"
fi

if [ $# -eq 2 ]; then
	n_bytes=$2
else 
	n_bytes=0
fi

echo $n_bytes


echo "Nombre LongitudUsuario FechaModificacion FechaAcceso Tamaño Bloques Permisos Ejecutable"
for file in $(find $1 -size +`$n_bytes`c -type f -or -size `$n_bytes`c -type f)
do
	LongitudUsuario=$(stat -c %U $file | wc -m)
	Permisos=$(stat -c %A $file)
	if [ Permisos[4] == "x" ]; then
		Ejecutable=1
	else
		Ejecutable=0
	fi

	echo "$(basename $file);$LongitudUsuario;$(stat -c %y $file);$(stat -c %x $file);$(stat -c %s $file);$(stat -c %b $file);$Permisos;$Ejecutable)"
done
