/*!
	\file operadoresExternosPolinomios.hpp
	\brief Ficheros con operadores de monomios y polinomios
*/

#ifndef _OperadoresPolinomios_HPP_
#define _OperadoresPolinomios_HPP_

// Facilita la entrada y salida
#include <iostream>

#include "Polinomio.hpp"

using std::istream;
using std::ostream;

// Espacio de nombre de la asigantura: ed
namespace ed
{

	//! \name Operadores de igualdad

	/**
	 * @brief Operador lógico de igualdad entre dos polinomios
	 * @param polinomio1: Polinomio situado a la izquierda del operador
	 * @param polinomio2
	 * @return true Si los monomios de cada polinomio coinciden uno a uno en grado y coeficiente
	 * @return false Si ocurre el caso contrario
	 */
	bool operator==(ed::Polinomio const & polinomio1, ed::Polinomio const & polinomio2);

	// COMPLETAR LOS OTROS OPERADORES DE IGUALDAD

	////////////////////////////////////////////////////////////////////////////////////
	//! \name Operadores de desigualdad

	// COMPLETAR LOS COMENTARIOS DE DOXYGEN
	bool operator!=(ed::Polinomio const & polinomio1, ed::Polinomio const & polinomio2);

	// COMPLETAR LOS OTROS OPERADORES DE DESIGUALDAD

//////////////////////////////////////////////////////////////////////////////////////

	//! \name Operadores unarios

	// COMPLETAR LOS COMENTARIOS DE DOXYGEN
		ed::Polinomio & operator+(ed::Polinomio const & p);

	// COMPLETAR EL OTRO OPERADOR UNARIO PREFIJO: resta


//////////////////////////////////////////////////////////////////////////////////////

	//! \name Operadores binarios de la suma

	// COMPLETAR LOS COMENTARIOS DE DOXYGEN
		ed::Polinomio & operator+(ed::Polinomio const &polinomio1,  ed::Polinomio const &polinomio2);

		// COMPLETAR LOS OTROS OPERADORES DE SUMA


		//////////////////////////////////////////////////////////
		//! \name Operador binario de la resta

		// COMPLETAR


		///////////////////////////////////////////////////////////////////////////
		//! \name Operadores binarios de la multiplicación

		// COMPLETAR

		///////////////////////////////////////////////////////////////////////////

		//! \name Operadores binarios de la división

		// COMPLETAR

	/////////////////////////////////////////////////////////////////////////////

   //! \name Sobrecarga de los operadores de flujo de la clase Polinomio.

    // COMPLETAR LOS COMENTARIOS DE DOXYGEN
    ostream &operator<<(ostream &stream, ed::Polinomio const &p);

    // COMPLETAR LOS COMENTARIOS DE DOXYGEN
    istream &operator>>(istream &stream, ed::Polinomio &p);

}  // Fin de namespace ed.

#endif // _OperadoresPolinomios_HPP_
