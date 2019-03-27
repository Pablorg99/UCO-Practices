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
using std::cout;
using std::cin;
using std::endl;

#include "Polinomio.hpp"
using ed::Polinomio;

//Constructores

Polinomio::Polinomio() {
	Monomio monomio(0, 0.0);
	getPolinomio().push_back(monomio);
}

Polinomio::Polinomio(const Polinomio &polinomio) {
	_vectorMonomios = polinomio.getPolinomio();
}


//Observadores

bool Polinomio::esNulo() const {
	if((getNumeroMonomios() == 1) && (getPolinomio().front().esNulo())) return true;
	else return false;
}

bool Polinomio::existeMonomio(int grado_monomio) const {
	vector <Monomio>::const_iterator monomio;
	for(monomio = getPolinomio().begin(); monomio != getPolinomio().end(); monomio++) {
		if(monomio->getGrado() == grado_monomio) return true;
	}
	return false;
}

Monomio Polinomio::getMonomio(int grado_monomio) const {
	Monomio monomio_nulo;
	if(existeMonomio(grado_monomio)) {
		vector <Monomio>::const_iterator monomio;
		for(monomio = getPolinomio().begin(); monomio != getPolinomio().end(); monomio++) {
			if(monomio->getGrado() == grado_monomio) return *monomio;
		}
	}
	else return monomio_nulo;
}

bool Polinomio::estaOrdenado() const {
	vector <Monomio>::const_iterator monomio;
	for(monomio = getPolinomio().begin(); monomio != getPolinomio().end(); monomio++) {
		if((monomio - 1)->getGrado() < monomio->getGrado()) return false;
	}
	return true;
}

//Modificadores

void ordenaPolinomio() {
	
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
	//Crea un polinomio vacío al que solo asigno un monomio
	Polinomio new_polinomio;
	new_polinomio.getPolinomio().assign(0, monomio);
	//Igualo el polinomio actual al creado
	*this = new_polinomio;
	return *this;
}


Polinomio & Polinomio::operator=(double const &numero_real) {
	//Creo un nuevo polinomio al que le asigno un monomio con coeficiente = numero_real y grado = 0
	Polinomio new_polinomio;
	new_polinomio.getPolinomio().front().setGrado(0);
	new_polinomio.getPolinomio().front().setCoeficiente(numero_real);
	//Igualo el polinomio actual al creado
	*this = new_polinomio;
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
	for(int i = 0; i < numero_monomios; i++) {
		cout << "-----------------" << endl;
		getPolinomio().at(i).leerMonomio();
		cout << "-----------------" << endl;
	}
	ordenaPolinomio();
}

void Polinomio::escribirPolinomio() {
	vector <Monomio>::iterator monomio;
	for(monomio = getPolinomio().begin(); monomio != getPolinomio().end(); monomio++) {
		cout << "-----------------" << endl;
		monomio->escribirMonomio();
		cout << "-----------------" << endl;
	}
}
///////////////////////////////////////////////////////////////////////

// Funciones auxiliares de la clase Polinomio

double Polinomio::calcularValor(double numero_real) {
	double resultado = 0.0;
	vector <Monomio>::iterator monomio;
	for(monomio = getPolinomio().begin(); monomio != getPolinomio().end(); monomio++) {
		resultado += monomio->calcularValor(numero_real);
	}
	return resultado;
}

