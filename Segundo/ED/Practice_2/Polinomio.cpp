/**
 * @file Polinomio.cpp
 * @author Pablo Rodríguez Guillén (i72rogup@uco.es)
 * @brief Fichero donde se implementa el TAD Polinomio
 * @version 0.1
 * @date 2019-31-03
 * @copyright Copyright (c) 2019
 */

// Ficheros de cabecera
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <algorithm>
using std::sort;

#include "Polinomio.hpp"
using ed::Polinomio;

#include "operadoresExternosPolinomios.hpp"

//Constructores
Polinomio::Polinomio() {
	Monomio monomio(0.0, 0);
	_vectorMonomios.push_back(monomio);
}

Polinomio::Polinomio(const Polinomio &polinomio) {
	_vectorMonomios = polinomio.getVector();
}

//Observadores

bool Polinomio::esNulo() const {
	if((getNumeroMonomios() == 1) && (getVector().front().esNulo())) return true;
	else return false;
}

bool Polinomio::existeMonomio(int grado_monomio) const {
	vector <Monomio>::const_iterator monomio;
	for(monomio = getVector().begin(); monomio != getVector().end(); monomio++) {
		if(monomio->getGrado() == grado_monomio) return true;
	}
	return false;
}

Monomio Polinomio::getMonomio(int grado_monomio) const {
	Monomio *monomio_nulo = new Monomio(0.0, 0);
	Monomio monomio_correcto;
	if(existeMonomio(grado_monomio)) {
		for(int i = 0; i < getNumeroMonomios(); i++) {
			if(_vectorMonomios[i].getGrado() == grado_monomio) return monomio_correcto = _vectorMonomios[i];
		}
	}
	return *monomio_nulo;
}

//Funciones privadas

bool Polinomio::_estaOrdenado() const {
	vector <Monomio>::const_iterator monomio;
	for(monomio = getVector().begin(); monomio != getVector().end(); monomio++) {
		if((monomio - 1)->getGrado() < monomio->getGrado()) return false;
	}
	return true;
}

void Polinomio::_ordenaPolinomio() {
	if (_estaOrdenado() == false) {
		vector <Monomio> ordered_vector;
		vector <Monomio>::iterator monomio_mayor = _vectorMonomios.begin();
		vector <Monomio>::iterator monomio;
		for(int i = 0; i < getNumeroMonomios(); i++) {
			for(monomio = getVector().begin(); monomio != getVector().end(); monomio++) {
				if(monomio_mayor->getGrado() < monomio->getGrado()) monomio_mayor = monomio;
			}
			ordered_vector[i] = *monomio_mayor;
			monomio_mayor = _vectorMonomios.erase(monomio_mayor);
		}
	setVector(ordered_vector);
	}
}

/////////////////////////////////////////////////////////////

// Operadores de asignación

Polinomio & Polinomio::operator=(Polinomio const &polinomio) {
	if(*this != polinomio) {
		//Utilizo el operador = por defecto
		*this = polinomio;
		return *this;
	}
	else return *this;
}


Polinomio & Polinomio::operator=(Monomio const &monomio) {
	//Vacía el polinomio de monomios
	_vectorMonomios.clear();
	//Añado el monomio al vector de monomios del polinomio y devuelvo el objeto
	_vectorMonomios.push_back(monomio);
	return *this;
}


Polinomio & Polinomio::operator=(double const &numero_real) {
	//Creo un monomio con coeficiente = numero_real y grado = 0
	Monomio monomio(0, numero_real);
	//Limpio el vector del polinomio y le añado unicamente el monomio creado
	_vectorMonomios.clear();
	_vectorMonomios.push_back(monomio);
	//Devuelvo el objeto actual
	return *this;
}

//////////////////////////////////////////////////////////////

//Operadores aritméticos y de asignación

//Suma

Polinomio & Polinomio::operator+=(Polinomio const &polinomio) {
	*this = *this + polinomio;
	return *this;
}

Polinomio & Polinomio::operator+=(Monomio const &monomio) {
	*this = *this + monomio;
	return *this;
}

Polinomio & Polinomio::operator+=(double numero_real) {
	*this = *this + numero_real;
	return *this;
}

//Resta 

Polinomio & Polinomio::operator-=(Polinomio const &polinomio) {
	*this = *this - polinomio;
	return *this;
}

Polinomio & Polinomio::operator-=(Monomio const &monomio) {
	*this = *this - monomio;
	return *this;
}

Polinomio & Polinomio::operator-=(double numero_real) {
	*this = *this - numero_real;
	return *this;
}

//Multiplicación

Polinomio & Polinomio::operator*=(Polinomio const &polinomio) {
	*this = *this * polinomio;
	return *this;
}

Polinomio & Polinomio::operator*=(Monomio const &monomio) {
	*this = *this * monomio;
	return *this;
}

Polinomio & Polinomio::operator*=(double numero_real) {
	*this = *this + numero_real;
	return *this;
}

//División

Polinomio & Polinomio::operator/=(Polinomio const &polinomio) {
	*this = *this / polinomio;
	return *this;
}

Polinomio & Polinomio::operator/=(Monomio const &monomio) {
	*this = *this / monomio;
	return *this;
}

Polinomio & Polinomio::operator/=(double numero_real) {
	*this = *this / numero_real;
	return *this;
}

///////////////////////////////////////////////////////////////////////

// Funciones lectura y escritura de la clase Polinomio

void Polinomio::leerPolinomio() {
	int numero_monomios;
	cout << "Introduzca el número de monomios que ha de tener el polinomio: ";
	cin >> numero_monomios;
	Monomio monomio_nulo(0.0, 0);
	_vectorMonomios.resize(numero_monomios, monomio_nulo);
	for(int i = 0; i < numero_monomios; i++) {
		cout << endl;
		_vectorMonomios[i].leerMonomio();
	}
	_ordenaPolinomio();
}

void Polinomio::escribirPolinomio() {
	for(int i = 0; i < getNumeroMonomios(); i++) {
		_vectorMonomios[i].escribirMonomio();
		cout << " ";
	}
	cout << endl;
}
///////////////////////////////////////////////////////////////////////

// Funciones auxiliares de la clase Polinomio

double Polinomio::calcularValor(double numero_real) {
	double resultado = 0.0;
	vector <Monomio>::iterator monomio;
	for(monomio = getVector().begin(); monomio != getVector().end(); monomio++) {
		resultado += monomio->calcularValor(numero_real);
	}
	return resultado;
}

