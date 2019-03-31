/**
 * @file Polinomio.hpp
 * @author Pablo Rodríguez Guillén (i72rogup@uco.es)
 * @brief Fichero de cabecera del TAD Polinomio
 * @version 0.1
 * @date 2019-31-03
 * @copyright Copyright (c) 2019
 */

#ifndef _POLINOMIO_HPP_
#define _POLINOMIO_HPP_

// Control de asertos
#include <cassert>

// Vector de STL
#include <vector>
using std::vector;

// Para usar la función abs
#include <cmath>

#include "PolinomioInterfaz.hpp"
#include "Monomio.hpp"
using ed::Monomio;


// Se incluye la clase Polinomio dentro del espacio de nombre de la asigantura: ed
namespace ed {

//!  Definición de la clase Polinomio que hereda de PolinomioInterfaz
class Polinomio: public ed::PolinomioInterfaz
{
	private:
		//! \name Atributos privados de la clase Polinomio
		vector <Monomio> _vectorMonomios;
		//! \name Funciones privadas de la clase Polinomio

		/**
		 * @brief Comprueba si el vector de monomios del polinomio que invoca este método esta ordenado por los grados de los monomios de mayor a menor
		 * @return true Si está ordenado
		 * @return false Si sucede lo contrario
		 */
		bool _estaOrdenado() const;
		
		/**
		 * @brief Utiliza el algoritmo de ordenación quicksort() para ordenar los monomios según su grado de mayor a menor
		 * @post El polinomio queda ordenado
		 */
		void _ordenaPolinomio();

	//! \name Funciones o métodos públicos de la clase Polinomio
	public:
		//! \name Constructores de la clase Polinomio

		/**
		 * @brief Construye un nuevo objeto Polinomio
		 * @note Función sobrecargada
		 * @post El polinomio creado es nulo
		 */
		Polinomio();

		/**
		 * @brief Constructor de copia del TAD Polinomio
		 * @note Función sobrecargada
		 * @param polinomio 
		 * @post El polinomio creado es una copia campo a campo de "polinomio"
		 */
		Polinomio(const Polinomio &polinomio);

		//! \name Observadores: funciones de consulta de la clase Polinomio

		/**
		 * @brief Devuelve el atributo privado _vectorMonomios de la clase Polinomio
		 * @note Permite que si la implementación del vector cambie, solo haya que modificar este observador privado
		 * @return vector <Monomio> 
		 */

		inline vector <Monomio> getVector() const {return _vectorMonomios;}

		/**
		 * @brief Comprueba si el Polinomio es igual a un monomio con grado y coeficientes 0 y 0.0
		 * @return true si el polinomio es igual al monomio con las características especificadas
		 * @return false si el polinomio no es igual al monomio mencionado
		 */
		bool esNulo() const;

		/**
		 * @brief Observador del grado del polinomio
		 * @pre Los monomios están ordenados de mayor a menor grado
		 * @return int: el mayor grado de los monomios que forman el polinomio
		 */
		inline int getGrado() const {return getVector().front().getGrado();}

		/**
		 * @brief Observador del numero de monomios del polinomio
		 * @note Función inline
		 * @return int: numero de elementos del vector "polinomio"
		 */
		inline int getNumeroMonomios() const {return getVector().size();}

		/**
		 * @brief Comprueba si existe un monomio dentro del polinomio con un determinado grado
		 * @param grado_monomio: grado del monomio a encontrar
		 * @return true si existe un monomio con el grado especificado
		 * @return false si no hay ningun monomio con dicho grado en el vector
		 */
		bool existeMonomio(int grado_monomio) const;

		/**
		 * @brief Observador de un monomio concreto
		 * @pre Existe el monomio de grado indicado
		 * @param grado_monomio: grado del monomio a encontrar
		 * @return Monomio: Objeto Monomio con el grado especificado
		 */
		Monomio getMonomio(int grado_monomio) const;

		//! \name Modificadores de la clase Polinomio

		/**
		 * @brief Modificador del vector de monomios que forma el polinomio
		 * @param new_vector: Vector que sustituye
		 * @post El polinomio insertado queda ordenado
		 */
		inline void setVector(vector <Monomio> &new_vector) {_vectorMonomios = new_vector; _ordenaPolinomio();}

	 	////////////////////////////////////////////////////////////////

		//! \name Operadores de la clase Polinomio

		/**
		 * @brief Copia el polinomio pasado como argumento (a la derecha del =) al polinomio actual
		 * @pre El polinomio copiado debe ser distinto al actual
		 * @note Función sobrecargada
		 * @param polinomio: Referencia constante al polinomio pasado
		 * @return Polinomio& 
		 */
		Polinomio & operator=(Polinomio const &polinomio);

		/**
		 * @brief Asigna al polinomio actual, únicamente el monomio de la derecha del igual
		 * @note Función sobrecargada
		 * @param monomio: Referencia constante al monomio pasado
		 * @return Polinomio& 
		 */
		Polinomio & operator=(Monomio const &monomio);

		/**
		 * @brief Copia en el polinomio actual, el numero pasado como argumento que es el situado a la derecha del =
		 * @note Función sobrecargada
		 * @param numero_real 
		 * @return Polinomio& 
		 * @post El polinomio solo contiene el número asignado como coeficiente y el grado es 0
		 */
		Polinomio & operator=(double const &numero_real);

		// Operadores aritméticos y asignación

		/**
		 * @brief Suma el polinomio actual con el polinomio pasado (a la derecha del operador)
		 * @note Función sobrecargada
		 * @param polinomio 
		 * @return Polinomio& 
		 */
		Polinomio & operator+=(Polinomio const &polinomio);

		/**
		 * @brief Suma el polinomio actual con el monomio pasado (a la derecha del operador)
		 * @note Función sobrecargada
		 * @param monomio 
		 * @return Polinomio& 
		 */
		Polinomio & operator+=(Monomio const &monomio);

		/**
		 * @brief Suma el numero a la derecha del operador al polinomio actual como un monomio de grado
		 * @note Función sobrecargada
		 * @param numero_real 
		 * @return Polinomio& 
		 */
		Polinomio & operator+=(double numero_real);

		/**
		 * @brief Resta al polinomio actual, el polinomio situado a la derecha del operador
		 * @note Función sobrecargada
		 * @param polinomio 
		 * @return Polinomio& 
		 */
		Polinomio & operator-=(Polinomio const &polinomio);
		
		/**
		 * @brief Resta al polinomio actual, el monomio situado a la derecha del operador
		 * @note Función sobrecargada
		 * @param monomio 
		 * @return Polinomio& 
		 */
		Polinomio & operator-=(Monomio const &monomio);
		
		/**
		 * @brief Resta al polinomio actual, un numero real que se entiende como un monomio de grado 0
		 * @note Función sobrecargada
		 * @param numero_real 
		 * @return Polinomio& 
		 */
		Polinomio & operator-=(double numero_real);

		/**
		 * @brief Multiplica el polinomio actual por el polinomio situado a la derecha del operador
		 * @note Función sobrecargada
		 * @param polinomio 
		 * @return Polinomio& 
		 */
		Polinomio & operator*=(Polinomio const &polinomio);
		
		/**
		 * @brief Multiplica el polinomio actual por el monomio situado a la derecha del operador
		 * @note Función sobrecargada
		 * @param monomio 
		 * @return Polinomio& 
		 */
		Polinomio & operator*=(Monomio const &monomio);
		
		/**
		 * @brief Multiplica el polinomio actual por un numero real, que se entiende como un monomio de grado 0
		 * @note Función sobrecargada
		 * @param numero_real 
		 * @return Polinomio& 
		 */
		Polinomio & operator*=(double numero_real);

		/**
		 * @brief Multiplica el polinomio actual por el polinomio situado a la derecha del operador
		 * @note Función sobrecargada
		 * @param polinomio 
		 * @return Polinomio& 
		 */
		Polinomio & operator/=(Polinomio const &polinomio);
		
		/**
		 * @brief Multiplica el polinomio actual por el monomio situado a la derecha del operador
		 * @note Función sobrecargada
		 * @param monomio 
		 * @return Polinomio& 
		 */
		Polinomio & operator/=(Monomio const &monomio);
		
		/**
		 * @brief Multiplica el polinomio actual por un numero real, que se entiende como un monomio de grado 0
		 * @note Función sobrecargada
		 * @param numero_real 
		 * @return Polinomio& 
		 */
		Polinomio & operator/=(double numero_real);
		
		///////////////////////////////////////////////////////////////////////

		//! \name Funciones lectura y escritura de la clase Polinomio

		/**
		 * @brief Pregunta al usuario cuantos monomios desea introducir y se hace tantas llamadas a leerMonomio() como sean necesarias
		 * @post Todos los monomios tienen grado positivo
		 */
		void leerPolinomio();

		/**
		 * @brief Imprime por pantalla todos los monomios del polinomio haciendo uso de escribirMonomio()
		 * @note Formato de un monomio: Coeficiente X^grado || Coeficiente 1: X^grado || Coeficiente -1: -X^grado || Grado 0: Coeficiente || Grado 1: X (sin grado)
		 */
		void escribirPolinomio() const;

		///////////////////////////////////////////////////////////////////////

		//! \name Funciones auxiliares de la clase Polinomio

		double calcularValor(double numero_real);

}; // Fin de la definición de la clase Polinomio

} // \brief Fin de namespace ed.

#endif //  _POLINOMIO_HPP_
