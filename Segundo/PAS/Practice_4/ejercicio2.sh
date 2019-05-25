#!/bin/bash

if [[ $# -ne 1 || ! -f $1 ]]; then
	echo "La ejecución correcta del programa es: ejercicio2.sh <rutaFichero.txt>"
	exit 1
fi

# |-> Fecha de estreno: 10/03/2017
# |-> Director: Jordan Vogt-Roberts
# |-> Reparto: Tom Hiddleston, Samuel L. Jackson, Brie Larson...
# |-> Fecha de estreno: 03/03/2017
# |-> Director: James Mangold
# |-> Reparto: Hugh Jackman, Patrick Stewart, Dafne Keen...

grep -E '^.+[^=+]$' peliculas.txt | sed -r 
'
	s/\(([0-9]{2}\/[0-9]{2}\/[0-9]{4})\)/|-> Fecha de estreno: \1/g;
    s/Dirigida por (.+)/|-> Director: \1/g;
    s/Reparto: (.+)/|-> Reparto: \1/g;
    s/^([1-9]hr\s.*min)/|-> Duración: \1/g;
'  
