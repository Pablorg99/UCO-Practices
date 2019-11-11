#!/bin/bash

read -p "Indique la dirección IP del servidor: " server_ip

SECONDS=0
echo "Ejecutando el cliente 10.000 veces..."
for iteration in {1..10000}; do
./prueba_client.out $server_ip SUMA 0 $iteration
done

calls_duration=$SECONDS
echo "Las 10.000 ejecuciones se han realizado en $calls_duration segundos."