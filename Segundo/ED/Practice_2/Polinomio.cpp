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
#include <cstdio>

#include <algorithm>
using std::sort;

#include "Polinomio.hpp"
using ed::Polinomio;

#include "operadoresExternosMonomios.hpp"
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
		//Igualo los objetos campo a campo
		this->_vectorMonomios = polinomio.getVector();
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
	Monomio monomio(numero_real, 0);
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
	//Se iteran los monomios del polinomio pasado
	for(int i = 0; i < polinomio.getNumeroMonomios(); i++) {
		//Si en el objeto actual existe un monomio con el mismo grado que el iterado
		if(this->existeMonomio(polinomio.getVector()[i].getGrado())) {
			//Se recorre el objeto actual y se modifica el monomio haciendo la suma correspondiente
			for(int j = 0; j < this->getNumeroMonomios(); j++) {
				if(this->getVector()[j].getGrado() == polinomio.getVector()[i].getGrado()) {
					this->getVector()[j] = this->getVector()[j] + polinomio.getVector()[i];
				}
			}
		}
		//Si no existe el monomio de la iteración, se añade al polinomio actual
		else this->getVector().push_back(polinomio.getVector()[i]);
	}
	this->_ordenaPolinomio();
	return *this;
}

Polinomio & Polinomio::operator+=(Monomio const &monomio) {
	bool sumado = false;
	for(int i = 0; i < this->getNumeroMonomios(); i++) {
		if(this->getVector()[i].getGrado() == monomio.getGrado()) {
			this->getVector()[i] = this->getVector()[i] + monomio;
			sumado = true;
		}
	}
	if(sumado == false) this->getVector().push_back(monomio);
	this->_ordenaPolinomio();
	return *this;
}

Polinomio & Polinomio::operator+=(double numero_real) {
	Monomio aux_monomio(numero_real, 0);
	return *this+=aux_monomio;
}

//Resta 

Polinomio & Polinomio::operator-=(Polinomio const &polinomio) {
	return *this+=(-polinomio);
}

Polinomio & Polinomio::operator-=(Monomio const &monomio) {
	Monomio aux_monomio = -monomio;
	return *this+=aux_monomio;
}

Polinomio & Polinomio::operator-=(double numero_real) {
	Monomio aux_monomio(-numero_real, 0);
	return *this+=aux_monomio;
}

//Multiplicación

Polinomio & Polinomio::operator*=(Polinomio const &polinomio) {
	for(int i = 0; i < polinomio.getNumeroMonomios(); i++) {
		*this *= polinomio.getVector()[i];
	}
	return *this;
}

Polinomio & Polinomio::operator*=(Monomio const &monomio) {
	for(int i = 0; i < getNumeroMonomios(); i++) {
		getVector()[i] = getVector()[i] * monomio;
	}
	return *this;
}

Polinomio & Polinomio::operator*=(double numero_real) {
	Monomio aux_monomio(numero_real, 0);
	return *this*=aux_monomio;
}

//División

Polinomio & Polinomio::operator/=(Polinomio const &polinomio) {
	return *this;
}

Polinomio & Polinomio::operator/=(Monomio const &monomio) {
	return *this;
}

Polinomio & Polinomio::operator/=(double numero_real) {
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

void Polinomio::escribirPolinomio() const {
	for(int i = 0; i < getNumeroMonomios(); i++) {
		_vectorMonomios[i].escribirMonomio();
	}
	cout << endl;
	getVector().begin()->escribirMonomio();
	cout << endl;
	vector <Monomio>::iterator it;
	for(it = getVector().begin(); it != getVector().end(); it++) {
		it->escribirMonomio();
	}
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

