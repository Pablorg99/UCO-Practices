#include "ej7.h"

void pedirNombre (char *file, int nchar) {
  fgets (file, nchar, stdin);
  for (int i = 0; i < strlen(file) + 1; i++) {
    if (file[i] == '\n') file[i] = '\0';
  }
}

int randomNumber(int min, int max) {
  int random;
  random = ((min + rand() % (max + 1 - min)));
  return random;
}

void rellenarFichero (char *file, int nEle, int min, int max) {
  FILE * f;
  if ((f = fopen(file, "w")) == NULL) {
    printf("Error al crear el archivo <%s>\n", file);
  }
  srand(time(NULL));
  for (int i = 0; i < nEle; i++) {
    fprintf(f, "%d\n", randomNumber(min, max));
  }
  fclose(f);
}
