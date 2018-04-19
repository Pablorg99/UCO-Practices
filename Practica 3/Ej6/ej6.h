#ifndef EJ6_H
#define EJ6_H

/* -----------------------------------------------------------------------------
6. Codifica un programa en C que, utilizando funciones, abra un fichero en modo
texto, cuyo nombre se pedirá al usuario, y genere un nuevo fichero llamado
“mayusculas-nombreFicheroDeEntrada.txt”, que tenga el mismo contenido que el
fichero original pero en mayúsculas.
-------------------------------------------------------------------------------*/

  #include <stdio.h>
  #include <string.h> //Permite el uso de strlen
  #include <ctype.h> //Permite el uso de toupper()

  /*----------------------------------------------------------------------------
  Esta función abre el archivo indicado por el usuario en la terminal y crea uno
  con el nombre indicado en el enunciado del ejercicio. Utilizando la lectura y
  escritura caracter a caracter (fgetc() y fputc()) escribe cada uno de los
  caracteres en el fichero final en mayúculas (usando la función toupper())
  ----------------------------------------------------------------------------*/
  void copyFileUpper (char *name);

#endif
