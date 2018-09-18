/*! 
    \file main.c
    \brief  Programa principal que permite resolver un crucigrama
    \note Metodología de la Programación
    \note Práctica 4
    \note Curso académico 2014-2015
*/

#include <stdio.h>
#include "ficheros.h"
#include "memoria.h"
#include "crucigrama.h"

/*!
 \fn int main()
 \brief Programa principal
 */
int main(){

  /* Comprueba si existe el fichero */
   existeFichero();

   /* Carga el fichero */
   cargaFicheroBinario();

   /* Reserva memoria para el crucigrama */
   reservaCrucigrama();

   /* Crea el crucigrama */
   creaCrucigrama();

   /* Imprime el crucigrama */
   imprimeCrucigrama(); 

   /* Se librera la memoria */
   liberaCrucigrama();  
      
   return 0;
}   

