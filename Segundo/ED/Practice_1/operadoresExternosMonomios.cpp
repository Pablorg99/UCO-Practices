//FILE PROVIDED BY UNIVERSITY

/*! 
   \file  operadoresExternosMonomios.cpp
	\brief Ficheros con el código de los operadores externos de la clase Monomio
*/


//  Ficheros de cabecera
#include <iostream>

#include "operadoresExternosMonomios.hpp"


//  Se incluyen los operadores sobrecargados dentro del espacio de nombres ed
namespace ed 
{
	// Operadores de igualdad
	bool operator==(ed::Monomio const & monomio_1, ed::Monomio const & monomio_2) {
		if(monomio_1.getGrado() == monomio_2.getGrado() && ((abs(monomio_1.getCoeficiente() - monomio_2.getCoeficiente())) < COTA_ERROR))
		{
		return true;
		}
		else return false;
	}

	bool operator==(ed::Monomio const & monomio, double numero_real) {
		if(monomio.getGrado() == 0 && (abs(monomio.getCoeficiente() - numero_real) < COTA_ERROR)) return true;
		else return false;
	}

	bool operator==(double numero_real, ed::Monomio const & monomio) {
		if(monomio.getGrado() == 0 && (abs(monomio.getCoeficiente() - numero_real) < COTA_ERROR)) return true;
		else return false;
	}

	// Operadores de desigualdad
	bool operator!=(ed::Monomio const & monomio_1, ed::Monomio const & monomio_2) {
		if(monomio_1.getGrado() == monomio_2.getGrado() && ((abs(monomio_1.getCoeficiente() - monomio_2.getCoeficiente())) < COTA_ERROR))
		{
		return false;
		}
		else return true;
	}

	bool operator!=(ed::Monomio const & monomio, double numero_real) {
		if(monomio.getGrado() == 0 && (abs(monomio.getCoeficiente() - numero_real) < COTA_ERROR)) return false;
		else return true;
	}

	bool operator!=(double numero_real, ed::Monomio const & monomio) {
		if(monomio.getGrado() == 0 && (abs(monomio.getCoeficiente() - numero_real) < COTA_ERROR)) return false;
		else return true;
	}

	////////////////////////////////////////////////////////////

	// Operadores unarios prefijos 

	// COMPLETAR
	ed::Monomio & operator+(ed::Monomio const & m)
	{
		// COMPLETAR Y MODIFICAR
		// Se crea un nuevo objeto
		ed::Monomio *nuevo = new ed::Monomio();


		// Se devuelve el resultado
		return *nuevo;
	}

	// COMPLETAR EL OTRO OPERADOR UNARIO PREFIJO: resta


	////////////////////////////////////////////////////////////
	// Operadores aritméticos binarios

	// Suma
	ed::Monomio & operator+ (ed::Monomio const &m1, ed::Monomio const &m2)
	{
		// COMPLETAR Y MODIFICAR
		// Se crea un nuevo objeto
		ed::Monomio *nuevo = new ed::Monomio();

	
		// Se devuelve el resultado
		return *nuevo;
	}


	////////////
	// Resta

	// COMPLETAR


	//////////////////
	// Multiplicación

	// COMPLETAR

	////////////
	// División

	// COMPLETAR


	/////////////////////////////////////////////////////////////////////////////

	//  Sobrecarga del operador de entrada
	istream &operator>>(istream &stream, ed::Monomio &m) 
	{
		// COMPLETAR

   		// Se devuelve el flujo de entrada
		return stream;
	}


	//  Sobrecarga del operador de salida
	ostream &operator<<(ostream &stream, ed::Monomio const &m) 
	{
		// COMPLETAR

		// Se devuelve el flujo de salida
		return stream;
	}


}  // namespace ed
