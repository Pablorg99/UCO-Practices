/*!
   \file operadoresExternosPolinomios.cpp
   \brief Fichero que contiene el código de las funciones de la clase Polinomio
*/


// Ficheros de cabecera
#include <iostream>

#include "operadoresExternosPolinomios.hpp"

#include "operadoresExternosMonomios.hpp"

// Se incluyen los operadores sobrecargados dentro del espacio de nombres de ed

namespace ed
{

bool operator==(ed::Polinomio const & p1, ed::Polinomio const & p2)
{
	// COMPLETAR Y MODIFICAR

	// MODIFICAR: SE DEVUELVE UN VALOR ARBITRARIO PARA NO GENERAR AVISOS AL COMPILAR
		return false;
}

// COMPLETAR LOS OTROS OPERADORES DE IGUALDAD



////////////////////////////////////////////////////////////////////////////////////
// Operadores de desigualdad
bool operator!=(ed::Polinomio const & p1, ed::Polinomio const & p2)
{
	// COMPLETAR Y MODIFICAR

	// MODIFICAR: SE DEVUELVE UN VALOR ARBITRARIO PARA NO GENERAR AVISOS AL COMPILAR
	return true;
}

// COMPLETAR LOS OTROS OPERADORES DE DESIGUALDAD

//////////////////////////////////////////////////////////////////////////////////////

// Operadores unarios

// COMPLETAR
ed::Polinomio & operator+(ed::Polinomio const & p)
{
	// COMPLETAR Y MODIFICAR
	// Se crea un nuevo objeto
	ed::Polinomio *nuevo = new ed::Polinomio(p);

	// Se devuelve el resultado
	return *nuevo;
}


// COMPLETAR EL OTRO OPERADOR UNARIO PREFIJO: resta


//////////////////////////////////////////////////////////////////////////////////////

// Operadores binarios de la suma
ed::Polinomio & operator+(ed::Polinomio const &p1,  ed::Polinomio const &p2)
{
	// COMPLETAR Y MODIFICAR
	// Se crea un nuevo objeto
	ed::Polinomio *nuevo = new ed::Polinomio;

	// Se devuelve el resultado
	return *nuevo;
}

	// COMPLETAR LOS OTROS OPERADORES DE SUMA

	////////////
	// Resta

	// COMPLETAR


	//////////////////
	// Multiplicación

	// COMPLETAR

	////////////
	// División

	// COMPLETAR


////////////////////////////////////////////////////////////////////////////

// Sobrecarga del operador de entrada
istream &operator>>(istream &stream, Polinomio &p)
{
	// COMPLETAR

	// Se devuelve el flujo de entrada
  return stream;
}



// Sobrecarga del operador de salida
ostream &operator<<(ostream &stream, Polinomio const &p)
{
	// COMPLETAR

	// Se devuelve el flujo de salida
  return stream;
}


} // Fin del espacio de nombres ed
