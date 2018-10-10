#include "ej8.h"

int main(int argc, char const *argv[]) {
  char *file;
  char *file_path = "../Ej7/";
  float media;
  //Comprueba si se ha introducido un solo argumento en la línea de órdenes.
  if (argc == 2) file = argv[1];
  //Si no es el caso, imprime mensaje de error y sale del programa.
  else {
    printf("Introduzca úncamente el nombre del archivo en la línea de ordenes");
    exit(-1);
  }

  file_path = fileInPath (file, file_path);
  media = mediaPares (file_path);
  printf("La media de los números pares de <%s> es: %f\n", file, media);
  free(file_path);
  return 0;
}
