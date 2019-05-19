#ifndef __FUNCIONES_HPP
#define __FUNCIONES_HPP

#include <iostream>
#include <cstring>
#include <cstdlib> // Para usar system
#include <fstream> // Para trabajar con ficheros
#include <sstream> // Para usar stringstream

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
bool cargarGrafo(Grafo<G_Nodo, G_Lado> * &g) {
    string ficheroMatriz, ficheroEtiquetas, aux;
    ifstream inputFile;
    int nodeCounter = 0;
    int index = 0;
    G_Nodo node;
    G_Lado edge;

    cout << "Fichero de la matriz de conexión: ";
    cin >> ficheroMatriz;
    cout << "Fichero de las etiquetas: ";
    cin >> ficheroEtiquetas;
    //Necesito reservar la memoria necesaria para la matriz, para ello calculo el número de nodos
    inputFile.open(ficheroEtiquetas.c_str());
    while(getline(inputFile, aux)) {
        nodeCounter++;
    }
    inputFile.close();
    g->allocateMemory(nodeCounter);
    // AHORA PASO LOS VALORES AL GRAFO
    // Cada línea del fichero de etiquetas es un nodo
    inputFile.open(ficheroEtiquetas.c_str());
    while(getline(inputFile, aux)) {
        node = aux;
        g->setNode(index, node);
        index++;
    }
    inputFile.close();
    // Traspaso la matriz de conexión a mi estructura grafo
    inputFile.open(ficheroMatriz.c_str());
    for (int row = 0; row < g->getNodeNumber(); ++row) {
        for (int column = 0; column < g->getNodeNumber() - 1; ++column) {
            getline(inputFile, aux, ' ');
            int lado = atoi(aux.c_str());
            edge = lado;
            g->setEdge(row, column, edge);
        }
        // Para recoger el último valor, el carácter separador debe cambiar
        getline(inputFile, aux, '\n');
        int lado = atoi(aux.c_str());
        edge = lado;
        g->setEdge(row, g->getNodeNumber() - 1, edge);
    }
    inputFile.close();
    g->printMatrix();
    g->printArray();
    return true;
}

template <class G_Nodo, class G_Lado>
void algoritmoFloyd(const Grafo<G_Nodo, G_Lado> &g)
{
  // TODO
}

#endif
