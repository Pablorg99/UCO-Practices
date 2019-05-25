#!/bin/bash

if [[ $# -ne 2 || ! -f $1 || $2 -lt 1 ]]; then
    echo "La ejecución correcta del programa tiene la siguiente forma: ejercicio4.sh <rutaFicheroIPs.txt> <segundosConsideraCaída>"
    exit 1
fi

for ip in $(cat $1); do
    # ping con -W devuelve un error (0, que equivale a false) si no se recibe respuesta tras el número de segundos especificado
    if ret=$(ping -c 1 -W $2 $ip); then
        # Capto con -o la expresión coincidente, el siguiente grep elimina el 'time' y el ' ms' para quedarme solo con el número
        time=$(ping $ip -c 1 | grep -Eo 'time=.+ms' | grep -Eo '[^time=].+[^ ms]')
        echo "La IP $ip respondión en $time milisegundos"
    else 
        echo "La IP $ip no respondió tras $2 segundos"
    fi
# Orden por columna 6 (Milisegundos cuando se responde y letra 't' cuando no)
# Opción de orden: alfanumérico (números primero, de menor a mayor y letras después, por orden alfabético)
done | sort -k6d 