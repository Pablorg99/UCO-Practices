#include "ej8.h"

int main(int argc, char const *argv[]) {
  char file[CHAR_FILE];
  char *file_path = "../Ej7/";
  float media;
  if (argc == 2) file = argv[1];
  else {
    printf("Introduzca úncamente el nombre del archivo en la línea de ordenes");
    exit(-1);
  }

  limpiarLinea (file);
  file_path = fileInPath (file, file_path);
  media = mediaPares (file_path);
  printf("La media de los números pares de <%s> es: %f\n", file, media);

  return 0;
}
