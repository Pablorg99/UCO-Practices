#!/bin/bash

if [[ $# -ne 0 ]]; then
    echo "Este script no requiere argumentos, si añade alguno no se utilizará."
fi

# El primer sed hace que solo se muestren las lineas necesarias, si no se incluye se mostrarían las características de cada procesador.
# El segundo sed hace que se seleccionen las referencias de los datos pedidos por el enunciado con una expresión que empareje con el formato del fichero.

cat /proc/cpuinfo | sed -n '2,13p' | sed -rn 's/model name[\t]*: (.+)/Modelo de procesador: \1/p; s/cpu MHz[\t]*: (.+)/Megahercios: \1/p; s/cpu cores[\t]*: (.+)/Número máximo de hilos en ejecución: \1/p; s/cache size[\t]*: (.+)/Tamaño de caché: \1/p; s/vendor_id[\t]*: (.+)/ID vendedor: \1/p'

# Al igual que en el ejercicio 3, cada [^ ]+ son los caracteres de una columna, se ponen entre parentesis los datos exigidos y se establece el formato en la segunda parte del comando s
cat /proc/mounts | sed -rn 's/^([^ ]+)\s+([^ ]+)\s+([^ ]+).*/Punto de montaje: \2, Dispositivo: \1, Tipo de dispositivo: \3/p'

# Misma estructura que el apartado anterior
cat /proc/partitions | sed -rn 's/^\s+[^ ]+\s+[^ ]+\s+([^ ]+)\s+([^ ]+).*/Partición: \2, Número Bloques: \1/p'