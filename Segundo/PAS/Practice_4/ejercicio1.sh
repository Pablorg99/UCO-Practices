#!/bin/bash

if [[ $# -ne 1 || ! -f $1 ]]; then
	echo "La ejecución correcta del programa es: ejercicio1.sh <rutaFichero.txt>"
	echo $1
	exit 1
fi

echo "*******"
# Al principio de una línea, un dígito del 1 al 9 seguido de las letras "hr", letras seguidas de un espacio y posteriormente, caracteres cualquiera y la palabra "min"
echo "1) Líneas con la duración de la película:"
grep -E --colour '^[1-9]hr\s.*min' $1

echo "*******"
# Coincide con todos los caracteres que estén comprendidos entre guiones
echo "2) Líneas con el país de las películas:"
grep -E --colour '\-.*\-' $1

echo "*******"
# Opción -o para mostrar solo el match sobre el apartado anterior, usando una pipe utilizo la misma opción para matchear todos los caracteres menos los guiones
echo "3) Solo el país de las películas:"
grep -Eo '\-.*\-' $1 | grep -Eo --colour '[^\-].*[^\-]'

echo "*******"
# Con la opción -c hago que se muestre solamente el número de líneas coincidentes. En cuanto a la expresión regular, hago que coincida con el formato de las fechas forzando que el último dígito sea 6 o 7 según me convenga.
echo "4) Hay $(grep -Ec --colour '([0-9]{2}/[0-9]{2}/[0-9]{3}6)' $1) películas del 2016 y $(grep -Ec --colour '([0-9]{2}/[0-9]{2}/[0-9]{3}7)' $1) películas del 2017"

echo "*******"
# Selecciono todas las líneas ^.*$, negando las que no contienen caracteres: ^$
echo "5) Eliminar las líneas vacías:"
grep -E --colour '.*[^\^$]' $1

echo "*******"
# Letra E señalando que pueda haber 0 o más espacios con el cuantificador *
echo "6) Líneas que empiezan con la letra E (con o sin espacios delante):"
grep -E --colour '^\s*E' $1

echo "*******"
# d(rangoVocales)d, de la misma manera con las letras l y t. El rango se especifica con el operador [...]
echo "7) Lı́neas que contienen d, l o t, una vocal y la misma letra:"
grep -E --colour 'd[aeiou]d|l[aeiou]l|t[aeiou]t' $1

echo "*******"
# Coincide con A o a pudiendo tener tanto delante como detrás cualquier caracter, todo esto se cuantifica con {8,} (8 o más)
echo "8) Líneas que contienen ocho aes o más:"
grep -E --colour '(.*(A|a).*){8,}' $1

echo "*******"
# Al inicio de línea especifico \S (igual que [^\s]), en medio puede haber cualquier caracter y al final debe haber 3 repeticiones del patrón "." (es necesario escapat el .)
echo "9) Líneas que terminan con tres puntos y no empiezan por espacio:"
grep -E --colour '^(\S).*(\.{3})$' $1

echo "*******"
# Con el comando set busco todas los vocales con tilde usando el rango [...] y reemplazo cada coincidencia (bandera g) con ella misma añadiendo comillas dobles. A la salida le aplico un grep con tubería para colorear la salida
echo "10) Mostrar entre comillas las claves con tilde:"
cat $1 | sed -r 's/([ÁÉÍÓÚáéíóú])/"\1"/g'| grep -E --colour '\"[ÁÉÍÓÚáéíóú]\"'
