#ifndef __ARBOLBINARIOORDENADO_HPP__
#define __ARBOLBINARIOORDENADO_HPP__

#include "operadornodo.hpp"

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
	class ArbolBinarioOrdenado
	{
	public:

		/*!\name Operaciones.
		@{
		*/

		/*!\brief Inserta un elemento en el árbol.

		Inserta en orden un elemento en el árbol. La insercción se realizará
		siempre como una hoja, por lo que el arbol no estará balanceado
		en general.

		Si ya existe x en el árbol, no se inserta.

		\arg[in] x referencia al valor del nodo a insertar
		\return true if el elemento se inserto o false si el elemento ya existía en el árbol
		*/
		virtual bool insertar(const G &x) = 0;

		/*!\brief Borra el árbol completo.

		Borra el árbol completo.
		*/
		virtual void borrarArbol() = 0;

		/*!\brief Borra un nodo del árbol.

		\arg[in] x referencia al valor del nodo a borrar
		\return true if el elemento existe y se borra o false si el elemento no existe y no se borra.

		*/
		virtual bool borrar() = 0;

		/*!\brief Realiza un recorrido pre-orden del árbol.

		Realiza un recorrido pre-orden del árbol, a partir de la raiz , aplicando un tratamiento definido por
		OperadorNodo.


		\arg[in] operador define la operación a realizar sobre cada nodo.
		*/
		virtual void recorridoPreOrden (OperadorNodo<G> &operador)const = 0;

		/*!\brief Realiza un recorrido postorden del árbol.

		Realiza un recorrido post-orden del árbol, a partir de la raiz, aplicando un tratamiento definido por
		OperadorNodo.


		\arg[in] operador define la operación a realizar sobre cada nodo.
		*/
		virtual void recorridoPostOrden (OperadorNodo<G> &operador) const = 0;

		/*!\brief Realiza un recorrido en-orden del árbol.

		Realiza un recorrido en-orden del árbol, a partir de la raiz, aplicando un tratamiento definido por
		OperadorNodo.


		\arg[in] operador define la operación a realizar sobre cada nodo.
		*/
		virtual void recorridoInOrden (OperadorNodo<G>& operador) const  = 0;

		/*!@}*/

		/*!\name Consultas.
		@{
		*/

		/*!\brief Busca un elemento.

		Busca un elemento en el árbol.

		\arg[in] x es el elemento a buscar.
		\return true si el elemento es encontrado, false en otro caso.
		*/
		virtual bool buscar (const G& x) const = 0;

		/*!\brief Comprueba si el árbol está vacío.
		\return true si el árbol está vacío y false si no lo está.
		*/
		virtual bool estaVacio() const = 0;

		/*!@}*/

	};

} //namespace ed

#endif //__ARBOLORDENADO_HPP__
