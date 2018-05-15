//Programa que visualiza un fichero binario de alumnos
#include <stdio.h>
#include <stdlib.h>

struct Ficha_alumno {
   char nombre[50];
   int DNI;
   float nota;
};

int existeFichero(char * texto);
void visualizaFichero(char * nombre);

int main(int argc, char * argv[]) {

   if (argc!=2) {
      printf("Sintaxis: %s <fichero_binario>\n",argv[0]);
      exit(-1);
   }
  
   if (!existeFichero(argv[1])){
      printf("El fichero %s no existe\n",argv[1]);
      exit(-1);
   }
   
   visualizaFichero(argv[1]);
  
   return 0;
}

int existeFichero(char * texto){
   FILE * f;
   f=fopen(texto,"r");
   if (f==NULL){
      return 0;
   }
   else {
      fclose(f);
      return 1;
   }
}

void visualizaFichero(char * nombre){
   FILE * f;
   struct Ficha_alumno ficha;
   
   f=fopen(nombre,"r");
   if (f==NULL){
      printf("Error al abrir el fichero %s\n",nombre);
      exit(-1);   
   }
   
   fread(&ficha,sizeof(struct Ficha_alumno),1,f);
   while (!feof(f)){
      printf("%s (%d) -> %lf\n",ficha.nombre,ficha.DNI,ficha.nota);
      fread(&ficha,sizeof(struct Ficha_alumno),1,f);
   }
   
   fclose(f);
}
