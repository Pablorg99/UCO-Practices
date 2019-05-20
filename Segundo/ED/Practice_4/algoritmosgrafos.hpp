#ifndef __ALGORITMOSGRAFOS_H__
#define __ALGORITMOSGRAFOS_H__

#include <iostream>
#include <vector>
#include "grafo.hpp"

using namespace ed;
using namespace std;

template <class G_Nodo, class G_Lado>
class AlgoritmosGrafos {
private:
    // Matrices de distancias y de recorridos
    G_Lado **_distancias;
    G_Nodo **_recorridos;
public:
    AlgoritmosGrafos(const Grafo<G_Nodo, G_Lado> &graph) {
        // Reserva de memoria e inicialización de valores para ambas matrices
        _distancias = new G_Lado *[graph.getNodeNumber()];
        _recorridos = new G_Nodo *[graph.getNodeNumber()];
        for (int i = 0; i < graph.getNodeNumber(); ++i) {
            _recorridos[i] = new G_Nodo[graph.getNodeNumber()];
            _distancias[i] = new G_Lado[graph.getNodeNumber()];
            for (int j = 0; j < graph.getNodeNumber(); ++j) {
                _recorridos[i][j] = graph.getNode(j);
                if (i == j) _distancias[i][j] = 0;
                else _distancias[i][j] = graph.getEdge(i, j);
            }
        }
    }

    void floydAlgorithm(const Grafo<G_Nodo, G_Lado> &graph) {
        for (int i = 0; i < graph.getNodeNumber(); ++i) {
            for (int j = 0; j < graph.getNodeNumber(); ++j) {
                for (int k = 0; k < graph.getNodeNumber(); ++k) {
                    if (_distancias[j][i] + _distancias[i][k] < _distancias[j][k]) {
                        _distancias[j][k] = _distancias[j][i] + _distancias[i][k];
                        _recorridos[j][k] = _recorridos[j][i];
                    }
                }
            }
        }
    }

    void askPath(const Grafo<G_Nodo, G_Lado> &graph) {
        vector <G_Nodo> pathArray;
        G_Lado cost;
        bool found = false;
        // PEDIDA DE DATOS AL USUARIO CON COMPROBACIÓN DE ERRORES
        G_Nodo origenNode, destinationNode;
        // Índices de nodos pedidos
        int origenIndex = -1;
        int destinationIndex = -1;
        cout << "Indique el nodo de origen: ";
        cin >> origenNode;
        origenIndex = getNodeIndex(origenNode, graph);
        while (origenIndex == -1) {
            cout << "El nodo introducido no existe, introduzca otro: ";
            cin >> origenNode;
            origenIndex = getNodeIndex(origenNode, graph);
        }
        cout << "Indique el nodo destino: ";
        cin >> destinationNode;
        destinationIndex = getNodeIndex(destinationNode, graph);
        while(destinationIndex == -1) {
            cout << "El nodo introducido no existe, introduzca otro: ";
            cin >> destinationNode;
            destinationIndex = getNodeIndex(destinationNode, graph);
        }
        // ALGORITMO QUE AÑADE LOS NODOS DEL CAMINO A UN VECTOR
        // Nodo de salida de cada iteración, la primera vez es el mismo que el pedido por el usuario
        int origenIterationIndex = origenIndex;
        while(! found) {
            // Añado el nodo salida de la iteración al camino
            pathArray.push_back(graph.getNode(origenIterationIndex));
            // Si he llegado al destino: found = true, si no, itero saliendo desde el nodo que indique la matriz de recorridos
            if(destinationNode == _recorridos[origenIterationIndex][destinationIndex]) found = true;
            else origenIterationIndex = getNodeIndex(_recorridos[origenIterationIndex][destinationIndex], graph);
        }
        // El cálculo de la distancia mínima es inmediato con la matriz de distancias de la clase
        cost = _distancias[origenIndex][destinationIndex];
        cout << "La distancia es: " << cost << endl;
        cout << "El camino es: ";
        for (size_t i = 0; i < pathArray.size(); i++) {
            cout << pathArray[i] << " -> ";
        }
        cout << destinationNode << endl;
    }

    int getNodeIndex(G_Nodo origenNode, const Grafo <G_Nodo, G_Lado> &graph) {
        for (int i = 0; i < graph.getNodeNumber(); ++i) {
            if(graph.getNode(i) == origenNode) return i;
        }
        return -1;
    }

    void printMatrices(const Grafo <G_Nodo, G_Lado> &graph) {
        cout << "DISTANCIAS" << endl;
        for (int i = 0; i < graph.getNodeNumber(); ++i) {
            for (int j = 0; j < graph.getNodeNumber(); ++j) {
                cout << _distancias[i][j] << " ";
            }
            cout << endl;
        }
        cout << "RECORRIDOS" << endl;
        for (int i = 0; i < graph.getNodeNumber(); ++i) {
            for (int j = 0; j < graph.getNodeNumber(); ++j) {
                cout << _recorridos[i][j] << " ";
            }
            cout << endl;
        }
    }
};

#endif
