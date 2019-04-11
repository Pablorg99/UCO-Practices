#!/bin/bash

# Comprueba el uso adecuado del script
if [ $# -lt 1 ] || [ $# -gt 3 ]; then
	echo "El uso correcto es: $ ejercicio3.sh <directorio> [umbral_bytes1] [umbral_bytes2]"
	exit 1
fi

# Establezco los valores por defecto
umbral1=10000
umbral2=100000

# Cambia los valores si corresponde
if [ $2 -ne 0 ]; then
	umbral1=$2
fi

if [ $3 -ne 0 ]; then
	umbral1=$3
fi

# Si el umbral menor se ha introducido después del mayor, se intercambian los valores
if [ $umbral1 -ge $umbral2 ]; then
	aux=$umbral2
	umbral2=$umbral1
	umbral1=$aux
fi

# Creacion de carpetas: "pequenos","medianos" y "grandes"
if [[ -d "pequenos" && "medianos" && "grandes" ]]; then
	rm -rf pequenos medianos grandes
	mkdir pequenos medianos grandes
	echo "Las carpetas de salida ya existen, se va a proceder a borrarlas..."
else
	echo "Creando las carpetas pequenos, medianos y grandes"
	mkdir pequenos medianos grandes
fi

echo "Copiando los archivos..."
echo "$umbral1"

# Ficheros pequeñosñ
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
