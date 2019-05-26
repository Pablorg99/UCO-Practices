#!/bin/bash

if [[ $# -ne 1 || ! -f $1 ]]; then
	echo "La ejecución correcta del programa es: ejercicio2.sh <rutaFichero.txt>"
	exit 1
fi

# ^[=]*$ ==> Líneas vacías o que solo contengan el carácter '=' un número cualquiera de veces

grep -v -E "^[=]*$" $1 | sed -r '/^ .+$/d; s/\(([0-9]{2}\/[0-9]{2}\/[0-9]{4})\) \-.+\-/|-> Fecha de estreno: \1/g; s/^Dirigida por (.+)$/|-> Director: \1/g; s/^Reparto: (.+)$/|-> Reparto: \1/g; s/([0-9]hr [0-9]{2}min)/|-> Duración: \1/g; s/^([^|].+)/Titulo: \1/g'

# Emparejamientos de expresiones regulares del sed:
# 1: ^ .+$/ ==> Empareja con las líneas que empiezan por un espacio (la sinopsis de las películas)
# 2: (([0-9]{2}\/[0-9]{2}\/[0-9]{4})\) \-.+\- ==> Empareja con líneas con el formato: (nn/nn/nnnn) -c- donde n es un dígito y c son un número cualquiera de caracteres cualesquiera. Los primeros paréntesis se escapan ya que quieren ser interpretados literalmente, no como argumento de 's'
# 3: ^Dirigida por (.+)$ ==> El argumento \1 corresponde a los carácteres que hay desde el final de 'Dirigida por ' hasta el final de la línea
# 4: ^Reparto: (.+)$ ==> Misma estructura de expresión regular que el apartado anterior
# 5: ([0-9]hr [0-9]{2}min) ==> Líneas del tipo: nhr nnmin donde n es un dígito cualquiera
# 6: ^([^|].+) ==> Todas las líneas que no empiezan por '|', que llegado a este punto, solo son títulos de película
