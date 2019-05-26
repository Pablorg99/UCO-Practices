#!/bin/bash

if [[ $# -ne 1 ]]; then
    echo "La ejecución correcta del programa tiene la siguiente forma: ejercicio6.sh <rutaShellPorDefecto>"
    exit 1
fi
# La expresión regular empareja con todas las líneas ya que todas utilizan el mismo formato. El carácter separador de campos es ':' y se ponen entre paréntesis los campos que va incluir la nueva cadena.
grep -E "$1" /etc/passwd | sed -re "s/^(.+):x:([0-9]+):([0-9]+):(.*):(.+):(.+)/=================\nLogname: \1\n->UID: \2\n->GID: \3\n->gecos: \4\n->Home: \5\n->Shell por defecto: \6/"
