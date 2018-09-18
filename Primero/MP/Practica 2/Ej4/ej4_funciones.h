/** ----------------------------------------------------------------------------
@file ej4_funciones.h
@brief Fichero de cabecera del ejercicio 4.
@date 3/04/2018
@version 1.0
@author Pablo Rodríguez Guillén

En este fichero se encuentran las funciones utilizadas en el ejercicio 4 de la
práctica 2 de MP. Cada una de ellas se encuentra en un fichero.c y para compilar
el ejercicio se han agrupado estos ficheros.c en una libreria.

------------------------------------------------------------------------------- */

#ifndef EJ4_FUNCIONES_H
#define EJ4_FUNCIONES_H

  #include <stdlib.h>
  #include <stdio.h>
  #include <time.h>

/**------------------------------------------------------------
@fn reservarMemoria(int nFil, int nCol)
@brief Reserva memoria para una matriz
@param nFil Número de filas de la Matriz
@param nCol Número de columnas de la Matriz
@return Double pointer that points to the matrix that you have reserved.

La función reserva la memoria necesaria para una matriz del numero de columnas y
de filas que se indican como parámetros mediante la función calloc, de manera
que inicializa todos los elementos de la matriz a 0.

------------------------------------------------------------- */
  int ** reservarMemoria (int nFil, int nCol);

  void rellenaMatriz (int **matriz, int nFil, int nCol);

  void imprimeMatriz (int **matriz, int nFil, int nCol);

  int * minCol (int **matriz, int nFil, int nCol);

  void liberarMemoria(int **matriz, int nFil);

#endif
