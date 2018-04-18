#include "ej6.h"

void copyFileUpper (char *name) {
  FILE * f_original;
  FILE * f_final;
  char c;

  if ((f_original = fopen(name, "r")) == NULL) {
    printf("Error al abrir el archivo <%s>\n",  name);
  }
  if ((f_final = fopen("mayusculas-nombreFicheroDeEntrada.txt", "w")) == NULL) {
    printf("Error al crear el archivo <%s>\n", "mayusculas-nombreFicheroDeEntrada.txt");
  }

  while ((c = fgetc (f_original)) != EOF) {
    fputc (toupper(c), f_final);
  }
  
  fclose(f_original);
  fclose(f_final);
}
