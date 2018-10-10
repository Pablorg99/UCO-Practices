#include "ej8.h"

char* fileInPath (char* file, char* file_path) {
  char *aux = malloc (1 + strlen(file) + strlen(file_path));
  strcpy(aux, file_path);
  strcat(aux, file);
  return aux;
}

float mediaPares (char *file) {
  FILE *f;
  float media = 0;
  int number, nEle = 0;
  if ((f = fopen(file, "r")) == NULL) {
    printf("No se ha podido abrir el fichero <%s>\n", file);
  }

  while ((fscanf (f, "%d", &number)) != EOF) {
    if (number % 2 == 0) {
      media += number;
      nEle++;
    }
  }
  media /= nEle;
  return media;
  fclose(f);
}
