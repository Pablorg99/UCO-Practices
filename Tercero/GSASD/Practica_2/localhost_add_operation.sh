#!/bin/bash

./prueba_server.out &
echo "Servidor iniciado."

SECONDS=0
echo "Ejecutando el cliente 10.000 veces..."
for i in {1..10000}; do
./prueba_client.out localhost SUMA 3 5 >> prueba_client.log
done

calls_duration=$SECONDS
echo "Las 100.000 ejecuciones se han realizado en $calls_duration segundos."

pkill prueba_server.o &