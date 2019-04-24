#!/bin/bash

# Check that the arguments are correct
if [ $# -ne 1 ] || [ ! -d "$1" ]; then
	echo "La ejecución correcta es: $ ejercicio6.sh <nombre_directorio>"
	exit 1
fi

htmlFile="$1.html"

# Loops through files with depth 1 and if the file is a directory, do a recursive call
function listFiles() {
	echo "<ul>" >> "$htmlFile"
	for file in $(find "$1" -maxdepth 1)
	do
	   	if [ -d "$file" ] && [ $file != $1 ]; then
   			echo "<li><strong>$file</strong></li>" >> $htmlFile
   			listFiles $file
 	  	elif [ $file != $1 ]; then 
   			echo "<li>$file</li>" >> $htmlFile
   		fi
	done
	echo "</ul>" >> "$htmlFile"
}

# Write all the html file structure and call listFile with the directory passed by the user 
echo "<head>" > "$htmlFile" 
echo "<title>Listado directorios de $1/</title>" >> "$htmlFile"
echo "</head>" >> "$htmlFile"
echo "<body>" >> "$htmlFile"
echo "<h1>Listado directorios de $1/</h1>" >> $htmlFile
listFiles $1
echo "</body>" >> "$htmlFile"
echo "</html>" >> "$htmlFile"

