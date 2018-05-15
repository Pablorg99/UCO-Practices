#include "ej11.h"

void pedirNombre (char *file, int nchar) {
  fgets (file, nchar, stdin);
  for (int i = 0; i < strlen(file) + 1; i++) {
    if (file[i] == '\n') file[i] = '\0';
  }
}

int * reservaVectorDinamico (int nEle) {
  int *ptrv;
  if ((ptrv = calloc(nEle, sizeof(int))) == NULL) {
    printf("Error al reservar memoria\n");
    exit(-2);
  }
  return ptrv;
}

int * getArrayFromFile (char *file, int *nEle) {
  int *vector;
  int aux;
  FILE *f;

  if ((f = fopen(file, "rb")) == NULL) {
    printf("Error al abrir el fichero <%s>\n", file);
    exit(-1);
  }

  fseek(f, 0L, SEEK_END);
  *nEle = ftell(f) / sizeof(int);
  vector = reservaVectorDinamico (*nEle);

  fseek(f, 0L, SEEK_SET);
  if ((fread (vector, sizeof(int), *nEle, f)) != *nEle){
    printf("Error en la lectura del fichero\n");
    exit(-4);
  }

  fclose(f);
  return vector;
}

void printVector (int * vector, int nEle) {
  printf("Vector = ");
  printf("{");
  for (int i = 0; i < nEle; i++) {
    if (i == nEle - 1) printf("%d", vector[i]);
    else printf("%d, ", vector[i]);
  }
  printf("}\n");
}

float mediaParesVector(int *vector, int nEle) {
  float nPar = 0, media = 0;
  for (int i = 0; i < nEle; i++) {
    if ((vector[i] % 2) == 0) {
      media += vector[i];
      nPar++;
    }
  }
  if (nPar == 0) {
    printf("No hay números pares\n");
    return 0;
  }
  media /= nPar;
  return media;
}
