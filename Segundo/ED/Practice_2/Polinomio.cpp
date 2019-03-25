/**
 * @file Polinomio.cpp
 * @author Pablo Rodríguez Guillén (i72rogup@uco.es)
 * @brief Fichero donde se implementa el TAD Polinomio
 * @version 0.1
 * @date 2019-03-05
 * @copyright Copyright (c) 2019
 */

// Ficheros de cabecera
#include <iostream>

#include "Polinomio.hpp"
using ed::Polinomio;

//Constructores

Polinomio::Polinomio() {
	Monomio monomio(0, 0.0);
	_vectorMonomios.push_back(monomio);
}

Polinomio::Polinomio(const Polinomio &polinomio) {
	_vectorMonomios = polinomio._vectorMonomios;
}

//Observadores

bool Polinomio::esNulo() const {
	if(getNumeroMonomios() == 1 && _vectorMonomios[0].esNulo()) return true;
	else return false;
}

bool Polinomio::existeMonomio(int grado_monomio) const {
	for(int i = 0; i < getNumeroMonomios(); i++) {
		if(_vectorMonomios[i].getGrado() == grado_monomio) return true;
	}
	return false;
}

Monomio Polinomio::getMonomio(int grado_monomio) const {
	Monomio monomio_nulo;
	if(existeMonomio(grado_monomio)) {
		for(int i = 0; i < getNumeroMonomios(); i++) {
			if(_vectorMonomios[i].getGrado() == grado_monomio) return _vectorMonomios[i];
		}
	}
	else return monomio_nulo;
}


// Operadores de asignación

/////////////////////////////////////////////////////////////

Polinomio & Polinomio::operator=(Polinomio const &polinomio)
{
	// COMPLETAR

	// Se devuelve el objeto actual
	return *this;
}


Polinomio & Polinomio::operator=(Monomio const &monomio)
{
	// COMPLETAR

	// Se devuelve el objeto actual
	return *this;
}


Polinomio & Polinomio::operator=(double const &numero_real)
{
	// COMPLETAR

	// Se devuelve el objeto actual
	return *this;
}

//////////////////////////////////////////////////////////////

Polinomio & Polinomio::operator+=(Polinomio const &polinomio)
{
	// COMPLETAR

	// Se devuelve el objeto actual
	return *this;
}

// COMPLETAR EL RESTO DE OPERADORES



///////////////////////////////////////////////////////////////////////

// Funciones lectura y escritura de la clase Polinomio

// COMPLETAR


///////////////////////////////////////////////////////////////////////

// Funciones auxiliares de la clase Polinomio

// COMPLETAR
