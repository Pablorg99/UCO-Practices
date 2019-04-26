#ifndef __ARBOLBINARIOORDENADO_HPP__
#define __ARBOLBINARIOORDENADOENLAZADO_HPP__

#include <iostream>
#include <cassert>
#include "arbolbinarioordenado.hpp"
#include "operadornodo.hpp"

using namespace std;
/*!
\brief Espacio de nombres para la asignatura Estructura de datos.
*/
namespace ed
{
	/*!\brief Interfaz para definir un ArbolBinario ordenado.

	Define una interfaz para definir un ArbolBinarioOrdenado.

	\arg G define el campo de información a contener en el arbol.
	\pre G debe tener definidos los operadores < y ==.
	*/
	template<class G>
	class ArbolBinarioOrdenadoEnlazado:public ArbolBinarioOrdenado<G>
	{
	private:

		/*!\brief Define un nodo del arbol binario.*/
		class NodoArbolBinario
		{
		private:
			G _info;  //Valor informativo almacenado en el nodo
			NodoArbolBinario * _izquierdo;  //Puntero al hijo izquierdo
			NodoArbolBinario * _derecho;  //Puntero al hijo derecho

		public:
			explicit NodoArbolBinario(const G &info)
			{
			    _info = info;
			    _derecho = NULL;
			    _izquierdo = NULL;
			}

			NodoArbolBinario(const NodoArbolBinario &nodo)
			{
				*this = nodo;
			}

			/*!\brief Observadores.*/
			const G & getInfo() const
			{
				return _info;
			}

			NodoArbolBinario *getIzquierdo() const
			{
				return _izquierdo;
			}

			NodoArbolBinario *getDerecho() const
			{
				return _derecho;
			}

			bool esHoja() const
			{
                return _derecho == NULL && _izquierdo == NULL;
            }

			void recorridoPreOrden (OperadorNodo<G> &operador) const
			{
				operador->aplicar(getInfo());
				if(getIzquierdo() != NULL) getIzquierdo()->recorridoPreOrden(operador);
				if(getDerecho() != NULL) getDerecho()->recorridoPreOrden(operador);
			}

			void recorridoPostOrden (OperadorNodo<G> &operador) const
			{
				if(getIzquierdo() != NULL) getIzquierdo()->recorridoPreOrden(operador);
				if(getDerecho() != NULL) getDerecho()->recorridoPreOrden(operador);
				operador->aplicar(getInfo());
			}

			void recorridoInOrden (OperadorNodo<G> &operador) const
			{
				if(getIzquierdo() != NULL) getIzquierdo()->recorridoPreOrden(operador);
				operador->aplicar(getInfo());
				if(getDerecho() != NULL) getDerecho()->recorridoPreOrden(operador);
			}

			/*!\brief Modificadores. */
			void setInfo(const G &info)
			{
				_info = info;
			}

			void setIzquierdo(NodoArbolBinario *nodo)
			{
				_izquierdo = *nodo;
			}

			void setDerecho(NodoArbolBinario *nodo)
			{
				_derecho = *nodo;
			}

			NodoArbolBinario & operator=(const NodoArbolBinario &nodo)
			{
				setInfo(nodo.getInfo());
				_derecho = nodo.getDerecho();
				_izquierdo = nodo.getIzquierdo();
			}

		}; //Fin clase NodoArbolBinario

		//Implementación de la raíz
		NodoArbolBinario * _raiz; /*!<La raíz del árbol*/
		NodoArbolBinario * _actual; /*!<Cursor al nodo actual*/
		NodoArbolBinario * _padre; /*!<Cursor al nodo actual*/

		// Métodos privados
        void _sucesorInmediato() {
            // Movemos el cursor una vez al hijo derecho para buscar en los mayores a actual
		    _padre = _actual;
		    _actual = _actual->getDerecho();
		    // Mientras exista un hijo izquierdo, movemos los cursores
		    while(_actual->getIzquierdo() != NULL) {
		        _padre = _actual;
                _actual = _actual->getIzquierdo();
		    }
		}

	public:

		ArbolBinarioOrdenadoEnlazado() = default;

		ArbolBinarioOrdenadoEnlazado (const ArbolBinarioOrdenadoEnlazado<G> &arbol)
		{
			*this = arbol;
		}

		~ArbolBinarioOrdenadoEnlazado()
		{
			if (! estaVacio())
			borrarArbol();
			cout << "Destructor Usado\n";
		}

		ArbolBinarioOrdenadoEnlazado &operator=(const ArbolBinarioOrdenadoEnlazado &arbol)
		{
			if(*this != arbol) {
				_raiz = arbol._raiz;
				_actual = arbol._actual;
				_padre = arbol._padre;
			}
		}

		bool insertar(const G &info)
		{
		    // Si el árbol está vacío se crea el nodo raíz con info
            if(estaVacio()) _raiz = NodoArbolBinario(info);
            else {
                _actual = _raiz;
                while(true) {
                    if(info > actual()) {
                        if(_actual->getDerecho() != NULL) _actual = _actual->getDerecho();
                        //Si el hijo apunta a NULL está vacío, por lo que se crea un nodo con info
                        else _actual->setDerecho(NodoArbolBinario(info)); return true;
                    }
                    else if(info < actual()) {
                        if(_actual->getIzquierdo() != NULL) _actual = _actual->getIzquierdo();
                        else _actual->setIzquierdo(NodoArbolBinario(info)); return true;
                    }
                    else {
                        return false;
                    }
                }
            }
		}

		void borrarArbol()
		{
			_raiz = NULL;
			_actual = NULL;
			_padre = NULL; 
		}

		bool borrar()
		{
			if(!existeActual()) return false;
			else {
			    // Si es hoja, se borra el hijo derecho/izquierdo del padre, según sea el actual
                if(_actual->esHoja()) {
                    // Si actual es el hijo izquierdo del padre
                    if(_padre->getIzquierdo() == _actual) _padre->setIzquierdo(NULL);
                    // Si es el derecho
                    else _padre->setDerecho(NULL);
                }
                // Si tiene 1 o 2 hijos
                else {
                    // Si actual solo tiene hijo derecho
                    if((_actual->getIzquierdo() == NULL) && (_actual->getDerecho() != NULL)) {
                        // Si actual es el hijo izquierdo del padre
                        if(_padre->getIzquierdo() == _actual) _padre->setIzquierdo(_actual->getDerecho());
                        // Si es el derecho
                        else _padre->setDerecho(_actual->getDerecho());
                    }
                    // Si actual solo tiene hijo izquierdo
                    else if((_actual->getDerecho() == NULL) && (_actual->getIzquierdo() != NULL)) {
                        // Si actual es el hijo izquierdo del padre
                        if(_padre->getIzquierdo() == _actual) _padre->setIzquierdo(_actual->getIzquierdo());
                        // Si es el derecho
                        else _padre->setDerecho(_actual->getIzquierdo());
                    }
                    // Tiene hijo derecho e izquierdo
                    else {
                        NodoArbolBinario * aux_actual = _actual;
                        // Movemos el cursor al sucesor inmediato
                        _sucesorInmediato();
                    }
                }
			}
		}

		void recorridoPreOrden(OperadorNodo<G> &operador) const
		{
			_raiz->recorridoPreOrden(operador);
		}

		void recorridoPostOrden(OperadorNodo<G> &operador) const
		{
			_raiz->recorridoPostOrden(operador);
		}

		void recorridoInOrden(OperadorNodo<G> &operador) const
		{
			_raiz->recorridoInOrden(operador);
		}

		bool buscar(const G& info) const
		{
            _actual = _raiz;
            _padre = NULL;
            //Mientras que exista un nodo hijo que comparar
            while(_actual != NULL) {
                if(actual() > info) {
                   _padre = _actual;
                   _actual = _actual->getIzquierdo();
                }
                else if(actual() < info) {
                    _padre = _actual;
                    _actual = _actual->getDerecho();
                }
                else {
                    return true;
                }
            }
            // Si no se encuentra el nodo, se pone _actual apuntando a raíz y padre a NULL y se devuelve false
            _actual = _raiz;
            _padre = NULL;
            return false;
		}

		bool estaVacio() const
		{
            return _raiz == NULL;
        }

		G raiz() const
		{
			if(! estaVacio()) return _raiz->getInfo();
		}

		bool existeActual() const
		{
			if(! estaVacio()) {
				if(_actual != NULL) return true;
			}
			return false;
		}

		G actual() const
		{
			if(existeActual()) return _actual->getInfo();
		}

		/* !@} */
	};

} //namespace ed

#endif //__ARBOLORDENADO_HPP__
