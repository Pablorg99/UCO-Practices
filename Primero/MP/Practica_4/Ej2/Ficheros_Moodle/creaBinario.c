// Programa que convierte un fichero de texto con alumnos en un fichero binario
#include <stdio.h>
#include <stdlib.h>

struct Ficha_alumno {
   char nombre[50];
   int DNI;
   float nota;
};

int lecturaRegistroTexto(FILE * f, struct Ficha_alumno * ficha);
void convertir (char * texto, char * binario);
int existeFichero(char * texto);

int main(int argc, char * argv[]) {

   if (argc!=3) {
      printf("Sintaxis: %s <fichero_texto> <fichero_binario>\n",argv[0]);
      exit(-1);
   }
  
   if (!existeFichero(argv[1])){
      printf("El fichero %s no existe\n",argv[1]);
      exit(-1);
   }
   
   convertir(argv[1],argv[2]);
  
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


void convertir (char * texto, char * binario) {
   FILE * ft, *fb;
   struct Ficha_alumno ficha;
   int fin;
   int escrito;
   
   ft=fopen(texto,"r");
   if (ft==NULL){
      printf("Error al abrir el fichero %s\n",texto);
      exit(-1);
   }
   
   fb=fopen(binario,"w");
   if (fb==NULL){
      printf("Error al abrir el fichero %s\n",binario);
      exit(-1);
   }
   
   fin=lecturaRegistroTexto(ft,&ficha);
   while (fin==0){
      escrito=fwrite(&ficha,sizeof(struct Ficha_alumno),1,fb);
      fin=lecturaRegistroTexto(ft,&ficha);
    
   }
   
   
   fclose(ft);
   fclose(fb);
   
}

int lecturaRegistroTexto(FILE * f, struct Ficha_alumno * ficha){
   int fin=1;
   char * dir;
   int leido;
   
   dir=fgets(ficha->nombre,50,f);
   if (dir!=NULL){
      leido=fscanf(f,"%d\n",&ficha->DNI);
      if (leido==1){
         leido=fscanf(f,"%f\n",&ficha->nota);
         if (leido==1){
            fin=0;
         }
      }
      
   }
   return fin;
}
