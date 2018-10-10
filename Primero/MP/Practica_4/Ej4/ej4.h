#ifndef EJ4_H
#define EJ4_H

/*------------------------------------------------------------------------------
• Descripción
  ◦ Un polinomio es una expresión algebraica de la forma:
    a n x n a n−1 x n−1 a n−2 x n−2 a 1 x a 0
    ▪ A cada a i x i se le denomina monomio, siendo a i el coeficiente del
      monomio e i el exponente del monomio.
    ▪ Se denomina polinomio a la suma algebraica de varios monomios.
    ▪ Algunos ejemplos de polinomios son:
      1 2x3
      2 x 3 7x 2 3x9
      3 2x 8 x 3 6x

  ◦ Un polinomio se puede representar como una lista enlazada.
    ▪ El primer nodo de la lista representa el primer monomio del polinomio, el
      segundo nodo el segundo monomio del polinomio, y así sucesivamente.
    ▪ Cada nodo representa un monomio del polinomio y tiene como campo dato el
      coeficiente del monomio (a) y el exponente (e).

  ◦ Escribe un programa que permita:
    ▪ Crear un polinomio. El programa preguntará al principio cuántos monomios
      tendrá el polinomio.
    ▪ Obtener una tabla de valores de un polinomio para valores de x = 0.0, 0.5,
      1.0, 1.5, ..., 5.0
      • Para el polinomio (1) tendríamos la siguiente salida:
      (x=0.0, 3), (x=0.5, 4), (x=1.0, 5), (x=1.5, 6), ..., (x=5.0, 13)
    ▪ Eliminar del polinomio el término con exponente E que se pedirá por
      pantalla.

• Objetivo
  ◦ Implementa para ello las siguientes funciones:
    ▪ anyadeMonomio. Inserta (por delante) un nuevo monomio en el polinomio.
    ▪ eliminaMonomio. Elimina, si existe, el monomio de exponente E (parámetro
      de la función).
    ▪ evaluaPolinomio. Evalúa el polinomio para un valor concreto de x.
    ▪ muestraPolinomio. Muestra por pantalla el polinomio.
------------------------------------------------------------------------------*/

typedef struct monomio {
  int coeficiente;
  int exponente;
  monomio *next;
}monomio;

  /*----------------------------------------------------------------------------
  
  ----------------------------------------------------------------------------*/
  addMonomio();

  /*----------------------------------------------------------------------------

  ----------------------------------------------------------------------------*/
  eliminaMonomio();

  /*----------------------------------------------------------------------------

  ----------------------------------------------------------------------------*/
  evaluaMonomio();

  /*----------------------------------------------------------------------------

  ----------------------------------------------------------------------------*/
  muestraMonomio();

#endif
