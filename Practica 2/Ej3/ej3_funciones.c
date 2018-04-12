#include "ej3_funciones.h"

ficha * reservarMemoria (int nJug) {
  ficha *jugadores = (ficha *) calloc (nJug, sizeof(ficha));
  if (jugadores == NULL) {
    printf("Se ha producido un error al reservar la memoria\n");
    exit(-1)
  }
  else return jugadores;
}

ficha leerJugador (ficha *jugador) {
  printf("Introduzca el nombre del nuevo jugador:\n");
  scanf("%s\n", jugador -> nombre);
  printf("Dorsal:\n");
  scanf("%i\n", jugador -> dorsal);
  printf("Peso:\n");
  scanf("%i\n", jugador -> peso);
  printf("Estatura:\n");
  scanf("%i\n", jugador -> estatura);
  return jugador;
}

void rellenarVectorJugadores (ficha *jugadores, int nJug) {
  for (int i = 0; i < nJug; i++) {
    jugadores[i] = leerJugador (jugadores[i]);
  }
}

void imprimirJugadores (ficha *jugadores, int nJug) {
  for (int i = 0; i < nJug; i++) {
    printf("Nombre Jugador: %s\n", jugador[i] -> nombre);
    printf("Dorsal: %s\n", jugador[i] -> dorsal);
    printf("Peso: %s\n", jugador[i] -> peso);
    printf("Estatura: %s\n", jugador[i] -> estatura);
  }
}

int borrarJugadores (ficha *jugadores, int nJug, char letra) {
  for (int i = 0; i < nJug; i++) {
    for (int j = 0; j < 50; j++) {
      if (letra == jugador[i] -> nombre[j]) {
        printf("Caracter encontrado\n");
        nJug--;
        jugador[i] = jugador[nJug]
      }
    }
  }
  jugadores = (ficha *) realloc (nJug, sizeof(ficha))
}
