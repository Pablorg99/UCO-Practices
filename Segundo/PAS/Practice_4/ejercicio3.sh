#!/bin/bash

if [ $# -gt 1 ]; then
    echo "La ejecución correcta del programa tiene la siguiente forma: ejercicio2.sh [rutaFichero]"
    exit 1
fi

echo "================"
echo "Listado de los archivos ocultos del directorio $HOME"
# ^\..* ==> Todas las cadenas que empiecen por . (se interpreta literalmente por eso se escapa)
ls -a $HOME | grep -E '^\..*'

echo "================"
# Se comprueba si se ha señalado un fichero existente como argumento
if [[ $# -ne 1 || ! -f $1 ]]; then
    echo "Si quiere hacer una copia de un fichero sin líneas vacías, añada la ruta del directorio como argumento del script"
else
    echo "El fichero $1 sin lineas vacías se ha guardado en $1.sinLineasVacias"
    # Empareja con todas las líneas que no estén vacías, esta salida se guarda en el fichero $1.sinLineasVacias usando el operador >
    grep -E '^.+$' $1 > $1.sinLineasVacias
fi

echo "================"
echo "Listado de procesos ejecutados por el usuario $USER"
# La salida del grep es la misma que la del ps menos la primera línea, que empieza por USER y acaba por COMMAND
# Cada [^ ]+ son todos los caracteres que no tengan espacio, es decir, una columna de ps, entre cada columna hay uno o más espacios (\s+)
ps -xu | grep -v -E '^USER.*COMMAND$' | sed -rn 's/[^ ]+\s+([^ ]+)\s+[^ ]+\s+[^ ]+\s+[^ ]+\s+[^ ]+\s+[^ ]+\s+[^ ]+\s+([^ ]+)\s+[^ ]+\s+(.*)$/PID: \1 Hora: \2 Ejecutable: \3/p'