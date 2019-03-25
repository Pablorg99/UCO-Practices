/**
 * @file Polinomio.hpp
 * @author Pablo Rodríguez Guillén (i72rogup@uco.es)
 * @brief Fichero de cabecera del TAD Polinomio
 * @version 0.1
 * @date 2019-03-05
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
	//! \name Atributos privados de la clase Polinomio
	private:
		vector <Monomio> _vectorMonomios;

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
		inline int getGrado() const {return _vectorMonomios[0].getGrado();}

		/**
		 * @brief Observador del numero de monomios del polinomio
		 * @note Función inline
		 * @return int: numero de elementos del vector "polinomio"
		 */
		inline int getNumeroMonomios() const {return _vectorMonomios.size();}

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

		//! \name Funciones de modificación de la clase Polinomio

	 	////////////////////////////////////////////////////////////////

		//! \name Operadores de la clase Polinomio

		/**
		 * @brief 
		 * 
		 * @param polinomio
		 * @return Polinomio& 
		 */
		Polinomio & operator=(Polinomio const &polinomio);

		/**
		 * @brief 
		 * 
		 * @param monomio 
		 * @return Polinomio& 
		 */
		Polinomio & operator=(Monomio const &monomio);

		/**
		 * @brief 
		 * 
		 * @param numero_real 
		 * @return Polinomio& 
		 */
		Polinomio & operator=(double const &numero_real);

		// Operadores aritméticos y asignación

		/**
		 * @brief 
		 * 
		 * @param polinomio 
		 * @return Polinomio& 
		 */
		Polinomio & operator+=(Polinomio const &polinomio);


		///////////////////////////////////////////////////////////////////////

		//! \name Funciones lectura y escritura de la clase Polinomio


		///////////////////////////////////////////////////////////////////////

		//! \name Funciones auxiliares de la clase Polinomio


}; // Fin de la definición de la clase Polinomio

} // \brief Fin de namespace ed.

#endif //  _POLINOMIO_HPP_
