#!/bin/bash

./prueba_server.out &
echo "Servidor local iniciado."

SECONDS=0
echo "Ejecutando el cliente 10.000 veces..."
for iteration in {1..10000}; do
./prueba_client.out localhost SUMA 0 $(echo $iteration)
done

calls_duration=$SECONDS
echo "Las 10.000 ejecuciones se han realizado en $calls_duration segundos."

pkill prueba_server.o &