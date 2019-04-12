#!/bin/bash

# If "~/Copia" doesn't exist, create it
if [ ! -d "$HOME/Copia" ]; then
	echo "Creando el directorio ~/Copia"
	mkdir ~/Copia
fi

# Iterates for each file in ~/Copia
# If $file is more than 200 seconds old, remove it
for file in $(find ~/Copia -type f)
do
	creation=$(stat $file -c %X)
	let time=$(date +%s)-$creation
	if [ $time -gt 5 ]; then
		echo "Borrando $file de $time segundos..."
		rm -f $file
	fi
done

# If there are 1 or more file/folder passed as argument, create a backup with them
if [ $# -gt 0 ]; then
	tar -czf ~/Copia/copia-$(whoami)-$(date +%s).tar.gz $*
	echo "La copia de seguridad se ha creado correctamente."
else 
	echo "Dado que no se ha especificado ningún fichero/carpeta como argumento, no se ha creado una copia de seguridad"
fi


