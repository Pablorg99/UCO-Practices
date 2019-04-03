#!/bin/sh
function pause(){
   read -p "Pulsa ENTER para continuar..."
}
 

set -x
gcc prueba.c
sudo mkdir directorio
sudo touch ./directorio/p1 ./directorio/p2
sudo chown root a.out
sudo chgrp root a.out
sudo chmod 701 a.out
ls -la
./a.out
set +x

echo "No te ha dejado porque el bit suid no estaba a 1"
pause

set -x
sudo chmod u+s a.out
ls -la
./a.out
set +x

echo "Ahora si te ha dejado!"
echo "Mostrando el contenido del fichero ./directorio/p1"
pause
sudo cat ./directorio/p1

