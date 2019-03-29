/*!
   \file PolinomioInterfaz.hpp
   \brief Definición de la interfaz de la clase Polinomio
*/

#ifndef _POLINOMIOINTERFAZ_HPP_
#define _POLINOMIOINTERFAZ_HPP_

#include "Monomio.hpp"

// Se incluye la clase PolinomioInterfaz dentro del espacio de nombre de la asigantura: ed
namespace ed {

//!  Definición de la clase PolinomioInterfaz
class PolinomioInterfaz
{
   	//! \name Funciones o métodos públicos de la clase
	public:
		//! \name Observadores: funciones de consulta
		
		/**
		 * @brief Función virtual del observador esNulo()
		 * @return 0 si no se implementa la función en la clase derivada (Polinomio)
		 */
		virtual bool esNulo() const = 0;
		
		/**
		 * @brief Función virtual del observador del grado del polinomio
		 * @return 0 si no se implementa la función en la clase derivada (Polinomio)
		 */
		virtual int getGrado() const = 0;
		
		/**
		 * @brief Función virtual del observador del numero de monomios del polinomio
		 * @return 0 si no se implementa la función en la clase derivada (Polinomio)
		 */
		virtual int getNumeroMonomios() const = 0;
		
		/**
		 * @brief Función virtual del método que comprueba la existencia de un monomio
		 * @param n: Grado del monomio en cuestión
		 * @return 0 si no se implementa la función en la clase derivada (Polinomio)
		 */
		virtual bool existeMonomio(int n) const = 0;
		
		/**
		 * @brief Observador que devuelve el monomio del grado indicado
		 * @param n: Grado del monomio en cuestión
		 * @return 0 si no se implementa la función en la clase derivada (Polinomio)
		 */
		virtual Monomio & getMonomio(int n) const = 0;
}; // Fin de la definición de la clase PolinomioInterfaz

} // \brief Fin de namespace ed.

//  _POLINOMIOINTERFAZ_HPP_
#endif
