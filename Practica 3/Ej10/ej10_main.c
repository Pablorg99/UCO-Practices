#include "ej10.h"

int main(int argc, char const *argv[]) {
  if (argc != 5) {
    printf("Introduce únicamente estos argumentos separados por espacios: \
    nombreFichero númeroElementosFichero númeroMáximo númeroMínimo\n");
    exit(-1);
  }
  char file[100];
  strcpy (file, argv[1]);

  /*----------------------------------------------------------------------------
  Utilizo la función strtol() para convertir los strings obtenidos en línea de
  órdenes en int.
  ptr es usado en la función para asignar el '\0' del string después del dato
  tipo int. Si ptr es distinto de '\0' se ha encontrado un caracter no válido
  antes del final de la cadena.
  El 10, corresponde a la base, que puede ser un nº entre 2 y 36, o el carácter
  especial 0.
  ----------------------------------------------------------------------------*/
  char *ptr;
  int aux;
  int nEle = strtol(argv[2], &ptr, 10);
  if (*ptr != '\0') {
    printf("Error al convertir númeroElementosFichero a int\n");
    exit(-2);
  }
  int max = strtol(argv[3], &ptr, 10);
  if (*ptr != '\0') {
    printf("Error al convertir númeroMáximo a int\n");
    exit(-2);
  }
  int min = strtol(argv[4], &ptr, 10);
  if (*ptr != '\0') {
    printf("Error al convertir númeroMínimo a int\n");
    exit(-2);
  }
  //Intercambia valores de max y min si están al revés.
  if (max < min) {
    aux = max;
    max = min;
    min = aux;
  }
  int *vector;

  vector = vectorDeAleatorios(nEle, min, max);
  writeInFile(file, vector, nEle);
  vector = readFile(file, vector, nEle);
  printVector (vector, nEle);

  free(vector);
  return 0;
}
