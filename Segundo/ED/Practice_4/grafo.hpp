#ifndef __GRAFO_HPP__
#define __GRAFO_HPP__

#include <cassert>
#include <iostream>

using namespace std;

namespace ed {

	template <class G_Nodo, class G_Lado>
	class Grafo	{
	private:
		G_Lado **_lados;
		G_Nodo *_nodos;
		int *_numeroNodos;

	public:
		Grafo() {
		    _numeroNodos = new int;
		    *_numeroNodos = 0;
		    _lados = new G_Lado*;
		    _nodos = new G_Nodo;
		}

        Grafo(int nodes) {
		    allocateMemory(nodes);
		}

		Grafo(const Grafo& graph) {
            *this = graph;
		}

		~Grafo() {
            borrarGrafo();
		}

		inline int getNodeNumber() const {
            return *_numeroNodos;
		}

		inline G_Nodo getNode(int index) const {
            return _nodos[index];
		}

		inline G_Lado getEdge(int row, int column) const {
            return _lados[row][column];
		}

		void setNode(int index, G_Nodo node) {
		    _nodos[index] = node;
		}

		void setEdge(int row, int column, G_Lado edge) {
		    _lados[row][column] = edge;
		}


        void allocateMemory(int nodes) {
            _numeroNodos = new int;
            *_numeroNodos = nodes;
            _nodos = new G_Nodo[*_numeroNodos];
            _lados = new G_Lado*[*_numeroNodos];
            for (int i = 0; i < *_numeroNodos; ++i) {
                _lados[i] = new G_Lado[*_numeroNodos];
            }
        }

        void printMatrix() {
            for (int i = 0; i < getNodeNumber(); ++i) {
                for (int j = 0; j < getNodeNumber(); ++j) {
                    cout << _lados[i][j] << " ";
                }
                cout << endl;
            }
            cout << endl;
		}

		void printArray() {
            for (int i = 0; i < getNodeNumber(); ++i) {
                cout << _nodos[i] << " ";
            }
            cout << endl;
		}

		void borrarGrafo() {
            delete [] _nodos;
            for (int i = 0; i < *_numeroNodos; ++i) {
                delete [] _lados[i];
            }
            delete [] _lados;
		    delete _numeroNodos;
            _numeroNodos = NULL;
            _nodos = NULL;
            _lados = NULL;
		}

		Grafo& operator=(const Grafo& graph) {
            // Reservo memoria para el entero y copio el del grafo pasado
            _numeroNodos = new int;
            *_numeroNodos = *graph._numeroNodos;
            // Reservo memoria para nodos y lados como en allocateMemory(int nodes)
		    _nodos = new G_Nodo[*_numeroNodos];
            _lados = new G_Lado*[*_numeroNodos];
            for (int i = 0; i < *_numeroNodos; ++i) {
                _lados[i] = new G_Lado[*_numeroNodos];
            }
            // Copio los valores los nodos del grafo pasado al actual
            for (int i = 0; i < *_numeroNodos; ++i) {
                _nodos[i] = graph._nodos[i];
            }
            // Hago lo propio con los lados
            for (int i = 0; i < *_numeroNodos; ++i) {
                for (int j = 0; j < *_numeroNodos; ++j) {
                    _lados[i][j] = graph._lados[i][j];
                }
            }
            return *this;
        }
	};
}

#endif
