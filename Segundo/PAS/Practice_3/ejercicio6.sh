#!/bin/bash

# Check that the arguments are correct
if [ $# -ne 1] || [ -d "$1" ] ; then
	echo "La ejecución correcta es: $ ejericico6.sh <nombre_directorio>"
fi


echo "<html>"
echo "<head>"
echo "<title><h3> Listado directiorios de $1 </h3></title>"
echo "</head>"
echo "<body>"
# listar archivos $1
echo "</body>"
echo "</html>"

# FUNCTION
function listar_archivos() {
	echo "<ul>"
	for x in $(find $1 -maxdepth 1) </ul>
	do
		<strong><li>$x</strong></li>
	done
}
