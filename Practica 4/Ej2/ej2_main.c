int main(int argc, char const *argv[]) {
  if (argc != 2) {
    printf("Introduce los siguientes argumentos en la línea de órdenes:\
    nombreFicheroBinario ascendente/descendente");
    exit(-1);
  }

  ficha *vector;
  int nFichas = 0;

  char *file = argv[1];
  char *file_path = "/Ficheros Moodle/"
  file_path = fileInPath (file, file_path);

  vector = getArrayFromFile (file_path, &nFichas);

  
  free (vector);
  return 0;
}
