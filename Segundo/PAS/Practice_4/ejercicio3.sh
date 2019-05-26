#!/bin/bash

if [ $# -gt 1 ]; then
    echo "La ejecución correcta del programa tiene la siguiente forma: ejercicio2.sh [rutaFichero]"
    exit 1
fi

echo "================"
echo "Listado de los archivos ocultos del directorio $HOME"
ls -a $HOME | grep -E '^\..*'

echo "================"
if [[ $# -ne 1 || ! -f $1 ]]; then
    echo "Si quiere hacer una copia de un fichero sin líneas vacías, añada la ruta del directorio como argumento del script"
else
    echo "El fichero $1 sin lineas vacías se ha guardado en $1.sinLineasVacias"
    sed -nr 's/(^.+$)/\1/p' $1 > $1.sinLineasVacias
fi

echo "================"