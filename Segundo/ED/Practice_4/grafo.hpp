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
		int _numeroNodos;

	public:
		Grafo() {
		    _lados = NULL;
		    _nodos = NULL;
		}

		Grafo(int nodes) {
		    _numeroNodos = nodes;
            _nodos = new G_Nodo[_numeroNodos];
		    _lados = new G_Lado*[_numeroNodos];
            for (int i = 0; i < _numeroNodos; ++i) {
                _lados[i] = new G_Lado[_numeroNodos];
            }
		}

		Grafo(const Grafo& graph) {
            *this = graph;
		}

		~Grafo() {
            borrarGrafo();
		}

		void borrarGrafo() {
            delete _nodos;
            for (int i = 0; i < _numeroNodos; ++i) {
                delete [] _lados[i];
            }
            delete [] _lados;
		}

		Grafo& operator=(const Grafo& graph) {
            // Copio el entero
            _numeroNodos = graph._numeroNodos;
            // Reservo memoria para nodos y lados como en el constructor Grafo(int nodes)
		    _nodos = new G_Nodo[_numeroNodos];
            _lados = new G_Lado*[_numeroNodos];
            for (int i = 0; i < _numeroNodos; ++i) {
                _lados[i] = new G_Lado[_numeroNodos];
            }
            // Copio los valores los nodos del grafo pasado al actual
            for (int i = 0; i < _numeroNodos; ++i) {
                _nodos[i] = graph._nodos[i];
            }
            // Hago lo propio con los lados
            for (int i = 0; i < _numeroNodos; ++i) {
                for (int j = 0; j < _numeroNodos; ++j) {
                    _lados[i][j] = graph._lados[i][j];
                }
            }
        }
	};
}

#endif
