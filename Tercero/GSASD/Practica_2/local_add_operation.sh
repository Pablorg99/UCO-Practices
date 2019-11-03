#!/bin/bash

SECONDS=0
echo "Ejecutando el programa suma_local 10.000 veces..."
for i in {1..10000}; do
./suma_local.out 3 5 >> suma_local.log
done

calls_duration=$SECONDS
echo "Las 100.000 ejecuciones se han realizado en $calls_duration segundos."