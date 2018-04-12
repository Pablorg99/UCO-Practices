#ifndef EJ3_FUNCIONES_H
#define EJ3_FUNCIONES_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Ficha_jugador{
  char nombre[50];
  int dorsal;
  float peso;
  int estatura;
}ficha;

ficha * reservarMemoria (int nJug);

ficha leerJugador (ficha jugador, int nJug);

void rellenarVectorJugadores (ficha *jugadores, int nJug);

void imprimirJugadores (ficha *jugadores, int nJug);

void borrarJugadores (ficha *jugadores, int nJug, char letra);

#endif
