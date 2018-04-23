#include "ej8.h"

void limpiarLinea (char* file) {
  for (int i = 0; i < strlen(file); i++) {
    if (file[i] == '\n') file[i] = '\0'
  }
}

char* fileInPath (char* file, char* file_path) {
   char *aux = malloc (1 + strlen(file) + strlen(file_path))
   strcpy(aux, file_path);
   strcat(aux, file);
   return aux;
}

float mediaPares (char *file) {
  FILE *f;
  if ((f = fopen(file, "r")) == NULL) {
    printf("No se ha podido abrir el fichero <%s>\n", );
  }
  fscanf(f, )
  fclose(f);
}
