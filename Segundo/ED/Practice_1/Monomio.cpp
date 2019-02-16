/*! 
   \file  Monomio.cpp
   \brief Fichero que contiene el código de las funciones de la clase Monomio
   \author Pablo Rodriguez Guillen
*/


//  Ficheros de cabecera
#include <iostream>

#include "Monomio.hpp"

ed::Monomio::Monomio(float coeficiente, int grado) {
	setCoeficiente(coeficiente);
	setGrado(grado);
}

/*
ed::Monomio & ed::Monomio::operator=(ed::Monomio const &m)
{
	
	// Se devuelve el objeto actual
	return *this;
}
*/

ed::Monomio ed::Monomio::operator=(float const numero_real) {
	setGrado(0);
	setCoeficiente(numero_real);
	// Se devuelve el objeto actual
	return *this;
}

ed::Monomio ed::Monomio::operator+=(Monomio const &monomio) {
	if(monomio.getGrado() == this->getGrado()) {
		this->setCoeficiente(this->getCoeficiente() + monomio.getCoeficiente());
	}
	//Se devuelve el objeto actual
	return *this;
}

// COMPLETAR EL RESTO DE OPERADORES



///////////////////////////////////////////////////////////////////////

// Funciones lectura y escritura de la clase Monomio

// COMPLETAR


///////////////////////////////////////////////////////////////////////

// Funciones auxiliares de la clase Monomio

// COMPLETAR

