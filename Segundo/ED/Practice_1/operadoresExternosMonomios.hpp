/*! 
	\file operadoresExternosMonomios.hpp
	\brief Ficheros con los prototipos de los operadores externos de la clase Monomio
	\author Pablo Rodriguez Guillen
*/

#ifndef _OperadoresExternosMonomios_HPP_
#define _OperadoresExternosMonomios_HPP_

// Facilita la entrada y salida
#include <iostream>

#include "Monomio.hpp"

// Para la sobrecarga de los operadores de flujo: << y >>
using std::istream;
using std::ostream;

// Espacio de nombre de la asigantura: ed
namespace ed
{
	//! \name Operadores de igualdad  

	/*!
		\brief Operador que comprueba si los 2 monomios que lo utilizan son iguales
		\note Funcion sobrecargada
		\param monomio_1: Referencia constante al monomio situado a la izquierda del operador
		\param monomio_2: Referencia constante al monomio situado a la derecha del operador
		\return true si los monomios tienen iguales coeficiente y grado, false en el caso contrario.
	*/ 
	bool operator==(ed::Monomio const & monomio_1, ed::Monomio const & monomio_2);

	/*!
		\brief Operador de igualdad con monomio a la izquierda y real a la derecha del operador
		\note Funcion sobrecargada
		\param monomio: Referencia constante del monomio que invoca el operador
		\param numero_real: numero de tipo double que se compara con el monomio
		\return true si el monomio es de grado 0 y su coeficiente es igual que numero_real, false en caso contrario
	*/
	bool operator==(ed::Monomio const & monomio, double numero_real);

	/*!
		\brief Operador de igualdad con real a la izquierda del operador y monomio a la derecha
		\note Funcion sobrecargada
		\param numero_real: numero de tipo double que invoca el operador al compararse con el monomio
		\param monomio: Referencia constante al monomio que se compara con el numero_real
		\return true si el monomio es de grado 0 y su coeficiente es igual que numero_real, false en caso contrario
	*/
	bool operator==(double numero_real, ed::Monomio const & monomio);

	//! \name Operadores de desigualdad 

	/*!
		\brief Operador de desigualdad entre dos monomios
		\note Funcion sobrecargada
		\param monomio_1: Referencia constante al monomio situado a la izquierda del operador
		\param monomio_2: Referencia constante al monomio situado a la derecha del operador
		\return true si los monomios tienen distinto grado o coeficiente, false en caso contrario
	*/
	bool operator!=(ed::Monomio const & monomio_1, ed::Monomio const & monomio_2);

	/*!
		\brief Operador de desigualdad entre un monomio a la izquierda del operador y un real a la derecha
		\note Funcion sobrecargada
		\param monomio: Referencia constante al monomio que invoca el operador
		\param numero_real: numero de tipo double que se compara con el monomio
		\return true si el monomio no es de grado 0 o su coeficiente no es igual que el real pasado, false en caso contrario
	*/
	bool operator!=(ed::Monomio const & monomio, double numero_real);

	/*!
		\brief Operador de desigualdad entre un real a la izquierda del operador y un monomio a la derecha
		\note Funcion sobrecargada
		\param numero_real: numero de tipo double que invoca el operador al compararse con el monomio
		\param monomio: Referencia constante al monomio que se compara con el real
		\return true si el monomio no es de grado 0 o su coeficiente no es igual que el real pasado, false en caso contrario
	*/
	bool operator!=(double numero_real, ed::Monomio const & monomio);

	//! \name Operadores unarios prefijos

	/*!
		\brief
	*/
	ed::Monomio & operator+(ed::Monomio const & monomio);

	/*!
		\brief
	*/
	ed::Monomio & operator-(ed::Monomio const & monomio);

	//! \name Operador binario de la suma 

	/*!
		\brief
	*/
	ed::Monomio & operator+ (ed::Monomio const &monomio_1, ed::Monomio const &monomio_2);

	//! \name Operador binario de la resta 

	/*!
		\brief
	*/
	ed::Monomio & operator- (ed::Monomio const &monomio_1, ed::Monomio const &monomio_2);

	//! \name Operadores binarios de la multiplicación 

	/*!
		\brief
	*/

	//! \name Operadores binarios de la división 

	/*!
		\brief
	*/

	//! \name Sobrecarga de los operadores de entrada y salida 

	/*!
		\brief
	*/
	istream &operator>>(istream &stream, ed::Monomio &monomio);

	/*!
		\brief
	*/
	ostream &operator<<(ostream &stream, ed::Monomio const &monomio);

}  // Fin de namespace ed.

#endif // _OperadoresExternosMonomios_HPP_


