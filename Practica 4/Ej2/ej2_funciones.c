ficha * reservarMemoriaVector(int nEle) {
  ficha *ptrv;
  ptrv = malloc(nEle * sizeof(ficha));
  return ptrv;
}

char* fileInPath (char* file, char* file_path) {
  char *aux = malloc (1 + strlen(file) + strlen(file_path));
  strcpy(aux, file_path);
  strcat(aux, file);
  return aux;
}

ficha * getArrayFromFile (char *file, int *nEle) {
  ficha *vector;
  ficha aux;
  FILE *f;

  if ((f = fopen(file, "rb")) == NULL) {
    printf("Error al abrir el fichero <%s>\n", file);
    exit(-2);
  }
  
  while ((fread(&aux, sizeof(int), 1, f)) == 1) (*nEle)++;
  vector = reservaVectorDinamico (*nEle);

  if ((fseek(f, 0L, SEEK_SET)) != 0) {
    printf("Error al reposicionar cursor del fichero\n");
    exit(-3);
  }
  if ((fread (vector, sizeof(int), *nEle, f)) != *nEle){
    printf("Error en la lectura del fichero\n");
    exit(-4);
  }

  fclose(f);
  return vector;
}
