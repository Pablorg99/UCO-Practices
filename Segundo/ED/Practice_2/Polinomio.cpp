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
	vector_monomios.push_back(monomio);
}

Polinomio::Polinomio(const Polinomio &polinomio) {
	vector_monomios = polinomio.vector_monomios;
}

bool esNulo() {

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
