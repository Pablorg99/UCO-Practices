#ifndef __FUNCIONES_HPP
#define __FUNCIONES_HPP

#include <iostream>
#include <cstring>
#include <cstdlib> //Para usar system
#include <fstream> //Para trabajar con ficheros

#include "grafo.hpp"
#include "algoritmosgrafos.hpp"

using namespace std;
using namespace ed;

int menu()
{
  int opcion;

  system("clear");
  cout << "  0. Salir................................\n";
  cout << "  1. Cargar grafo desde fichero...........\n";
  cout << "  2. Algoritmo de Floyd (GD y GND)......\n";

  cout << "Introduzca opcion...:";
  cin >> opcion;

  return opcion;
}

template <class G_Nodo, class G_Lado>
bool cargarGrafo(Grafo<G_Nodo, G_Lado> * &g)
{
  string ficheroMatriz, ficheroEtiquetas;

  cout << "Fichero de la matriz de conexion: ";
  cin >> ficheroMatriz;

  cout << "Fichero de las etiquetas: ";
  cin >> ficheroEtiquetas;

  // TODO

}

template <class G_Nodo, class G_Lado>
void algoritmoFloyd(const Grafo<G_Nodo, G_Lado> &g)
{
  // TODO
}

#endif
