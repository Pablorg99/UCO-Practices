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
			NodoArbolBinario (const G &info)
			{
			    _info = info;
			    _derecho = NULL;
			    _izquierdo = NULL;
			}

			NodoArbolBinario (const NodoArbolBinario &nodo)
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
				if(_derecho == NULL && _izquierdo == NULL) return true;
				return false;
			}

			void recorridoPreOrden (OperadorNodo<G> &operador) const
			{
				operador->aplicar(getInfo());
				if(getIzquierdo() != NULL) getIzquierda()->recorridoPreOrden(operador);
				if(getDerecho() != NULL) getDerecho()->recorridoPreOrden(operador);
			}

			void recorridoPostOrden (OperadorNodo<G> &operador) const
			{
				if(getIzquierdo() != NULL) getIzquierda()->recorridoPreOrden(operador);
				if(getDerecho() != NULL) getDerecho()->recorridoPreOrden(operador);
				operador->aplicar(getInfo());
			}

			void recorridoInOrden (OperadorNodo<G> &operador) const
			{
				if(getIzquierdo() != NULL) getIzquierda()->recorridoPreOrden(operador);
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
				_derecho = *nodo
			}

			NodoArbolBinario & operator=(const NodoArbolBinario &nodo)
			{
				_info = nodo.getInfo();
				_derecho = nodo.getDerecho();
				_izquierdo = nodo.getIzquierdo();	
			}

		}; //Fin clase NodoArbolBinario

		//Implementación de la raíz
		NodoArbolBinario * _raiz; /*!<La raiz del árbol*/
		NodoArbolBinario * _actual; /*!<Cursor al nodo actual*/
		NodoArbolBinario * _padre; /*!<Cursor al nodo actual*/

	public:

		ArbolBinarioOrdenadoEnlazado ()
		{

		}

		ArbolBinarioOrdenadoEnlazado (const ArbolBinarioOrdenadoEnlazado<G>& arbol)
		{
			*this = a;

		}

		~ArbolBinarioOrdenadoEnlazado ()
		{
			if (not estaVacio())
			borrarArbol();
			cout << "Destructor Usado \n";
		}

		ArbolBinarioOrdenadoEnlazado &operator=(const ArbolBinarioOrdenadoEnlazado& arbol)
		{
			if(*this != arbol) {
				_raiz = arbol._raiz;
				_actual = arbol._actual;
				_padre = arbol._padre
			}
		}

		bool insertar(const G &x)
		{
			
			return false;
		}

		void borrarArbol()
		{
			_raiz = NULL;
			_actual = NULL;
			_padre = NULL; 
		}

		bool borrar()
		{
			// TODO
			return false;
		}

		void recorridoPreOrden (OperadorNodo<G> &operador) const
		{
			// TODO
		}

		void recorridoPostOrden (OperadorNodo<G> &operador) const
		{
			// TODO
		}

		void recorridoInOrden (OperadorNodo<G> &operador) const
		{
			// TODO
		}

		bool buscar(const G& x) const
		{
			// TODO
			return false;
		}

		bool estaVacio() const
		{
			if(_raiz == NULL) return true;
			return false;
		}

		G raiz() const
		{
			if(this->estaVacio() == false) return _raiz->getInfo();
			else return NULL;
		}

		bool existeActual() const
		{
			if(estaVacio() == false) {
				if(_actual != NULL) return true;
			}
			return false;
		}

		G actual() const
		{
			if(existeActual()) return _actual;
			else return false;
		}

		/* !@} */
	};

} //namespace ed

#endif //__ARBOLORDENADO_HPP__
