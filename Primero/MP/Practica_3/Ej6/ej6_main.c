#include "ej6.h"

int main() {
  char file[30];
  printf("Introduzca el nombre del fichero que quiere copiar: ");
  //fgets() permite guardar una cadena con espacios en blanco, no como scanf()
  fgets (file, 30, stdin);
  //Para quitar el '\n' que se guarda en <file> por fgets
  for (int i = 0; i < strlen(file) + 1; i++) {
    if (file[i] == '\n') file[i] = '\0';
  }
  copyFileUpper(file);
  printf("\nSe ha creado una copia del fichero <%s> en mayúsculas con nombre <%s>\n", file, "mayusculas-nombreFicheroDeEntrada.txt");
}
