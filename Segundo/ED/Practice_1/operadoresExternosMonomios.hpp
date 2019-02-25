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
using std::getline;

//Para el uso de strings
#include <string>
using std::string;
//Para el uso de funciones de conversion de cadenas
#include <cstdlib>

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
	bool operator==(Monomio const & monomio_1, Monomio const & monomio_2);

	/*!
		\brief Operador de igualdad con monomio a la izquierda y real a la derecha del operador
		\note Funcion sobrecargada
		\param monomio: Referencia constante del monomio que invoca el operador
		\param numero_real: numero de tipo double que se compara con el monomio
		\return true si el monomio es de grado 0 y su coeficiente es igual que numero_real, false en caso contrario
	*/
	bool operator==(Monomio const & monomio, double numero_real);

	/*!
		\brief Operador de igualdad con real a la izquierda del operador y monomio a la derecha
		\note Funcion sobrecargada
		\param numero_real: numero de tipo double que invoca el operador al compararse con el monomio
		\param monomio: Referencia constante al monomio que se compara con el numero_real
		\return true si el monomio es de grado 0 y su coeficiente es igual que numero_real, false en caso contrario
	*/
	bool operator==(double numero_real, Monomio const & monomio);

	//! \name Operadores de desigualdad 

	/*!
		\brief Operador de desigualdad entre dos monomios
		\note Funcion sobrecargada
		\param monomio_1: Referencia constante al monomio situado a la izquierda del operador
		\param monomio_2: Referencia constante al monomio situado a la derecha del operador
		\return true si los monomios tienen distinto grado o coeficiente, false en caso contrario
	*/
	bool operator!=(Monomio const & monomio_1, Monomio const & monomio_2);

	/*!
		\brief Operador de desigualdad entre un monomio a la izquierda del operador y un real a la derecha
		\note Funcion sobrecargada
		\param monomio: Referencia constante al monomio que invoca el operador
		\param numero_real: numero de tipo double que se compara con el monomio
		\return true si el monomio no es de grado 0 o su coeficiente no es igual que el real pasado, false en caso contrario
	*/
	bool operator!=(Monomio const & monomio, double numero_real);

	/*!
		\brief Operador de desigualdad entre un real a la izquierda del operador y un monomio a la derecha
		\note Funcion sobrecargada
		\param numero_real: numero de tipo double que invoca el operador al compararse con el monomio
		\param monomio: Referencia constante al monomio que se compara con el real
		\return true si el monomio no es de grado 0 o su coeficiente no es igual que el real pasado, false en caso contrario
	*/
	bool operator!=(double numero_real, Monomio const & monomio);

	//! \name Operadores unarios prefijos

	/*!
		\brief Operador unario prefijo + que devulve una copia del monomio que invoca el operador
		\param monomio: Referencia al objeto de tipo monomio que invoca el operador
	*/
	Monomio & operator+(Monomio const & monomio);
	
	/*!
		\brief Operador unario prefijo - que devuelve una copia negativa del monomio que invoca el operador
		\post El objeto devuelto tiene el mismo grado que el inicial pero su coeficiente es el opuesto
	*/

	Monomio & operator-(Monomio const & monomio);

	//! \name Operador binario de la suma 

	/*!
		\brief Operador + entre dos monomios
		\param monomio_1: Referencia constante al monomio a la izquierda del operador
		\param monomio_2: Referencia constante al monomio a la derecha del operador
		\pre Ambos monomios deben tener el mismo grado
		\return Monomio resultante de la suma de los monomios, mismo grado y suma de coeficientes
	*/
	Monomio & operator+(Monomio const &monomio_1, Monomio const &monomio_2);

	//! \name Operador binario de la resta 

	/*!
		\brief Operador - entre dos monomios 
		\param monomio_1: Referencia constante al monomio a la izquierda del operador
		\param monomio_2: Referencia constante al monomio a la derecha del operador, que se resta a monomio_1
		\pre Ambos monomios deben tener el mismo grado
		\return Monomio resultante de la resta de los monomios, mismo grado y resta de coeficientes, NULL si no se cumple la precondicion
	*/
	Monomio & operator-(Monomio const &monomio_1, Monomio const &monomio_2);

	//! \name Operadores binarios de la multiplicación 

	/*!
		\brief Operador *  entre dos monomios
		\param monomio_1: Referencia constante al monomio a la izquierda del operador
		\param monomio_2: Referencia constante al monomio a la derecha del operador
		\return Monomio resultante de operar, suma de grados y producto de coeficientes
	*/
	Monomio operator*(Monomio const &monomio_1, Monomio const &monomio_2);

	/*!
		\brief Operador * entre un numero real a la derecha y un monomio a la izquierda
		\param numero_real: Numero que multiplica al coeficiente del monomio
		\param monomio: Referencia constante al monomio pasado como argumento
		\return Monomio resultante de la operacion
	*/
	Monomio & operator*(double numero_real, Monomio const &monomio);

	/*!
		\brief Operador * entre un numero real a la izquierda y un monomio a la derecha
		\param numero_real: Numero que multiplica al coeficiente del monomio
		\param monomio: Referencia constante al monomio pasado como argumento
		\return Monomio resultante de la operacion
	*/
	Monomio & operator*(Monomio const &monomio, double numero_real);

	//! \name Operadores binarios de la división 

	/*!
		\brief Operacion / entre dos monomios
		\param monomio_1: Referencia constante al monomio a la izquierda del operador
		\param monomio_2: Referencia constante al monomio a la derecha del operador, que divide a monomio_1
		\return Monomio resultante de operar, resta de grados y division de coeficientes
	*/
	Monomio & operator/(Monomio const &monomio_1, Monomio const &monomio_2);

	/*!
		\brief Operador / entre un numero real a la derecha y un monomio a la izquierda
		\param numero_real: Numero que divide al coeficiente del monomio
		\param monomio: Referencia constante al monomio pasado como argumento
		\return Monomio resultante de la operacion
	*/
	Monomio & operator/(double numero_real, Monomio const &monomio);

	/*!
		\brief Operador / entre un numero real a la izquierda y un monomio a la derecha
		\param numero_real: Numero que divide al coeficiente del monomio
		\param monomio: Referencia constante al monomio pasado como argumento
		\return Monomio resultante de la operacion
	*/
	Monomio & operator/(Monomio const &monomio, double numero_real);

	//! \name Sobrecarga de los operadores de entrada y salida 

	/*!
		\brief
	*/
	istream &operator>>(istream &stream, Monomio &monomio);

	/*!
		\brief
	*/
	ostream &operator<<(ostream &stream, Monomio const &monomio);

}  // Fin de namespace ed.

#endif // _OperadoresExternosMonomios_HPP_


