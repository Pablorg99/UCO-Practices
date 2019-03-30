/*! 
   \file  Monomio.cpp
   \brief Fichero que contiene el código de las funciones de la clase Monomio
   \author Pablo Rodriguez Guillen
*/


//  Ficheros de cabecera
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <string>
using std::string;

#include "Monomio.hpp"
using ed::Monomio;

//Constructores
Monomio::Monomio(double coeficiente, int grado) {
	setCoeficiente(coeficiente);
	setGrado(grado);
}

Monomio::Monomio(Monomio const &monomio) {
	setCoeficiente(monomio.getCoeficiente());
	setGrado(monomio.getGrado());
}

//Observadores
bool Monomio::esNulo() const {
	if(getGrado() == 0 && (abs(getCoeficiente() - 0.0) < COTA_ERROR)) return true;
	else return false;
}

///////////////////////////////////////////////////////////////////////////////////

//Operadores de asignación

Monomio & Monomio::operator=(Monomio const &monomio) {
	setCoeficiente(monomio.getCoeficiente());
	setGrado(monomio.getGrado());
	// Se devuelve el objeto actual
	return *this;
}

Monomio & Monomio::operator=(double const numero_real) {
	setGrado(0);
	setCoeficiente(numero_real);
	// Se devuelve el objeto actual
	return *this;
}

///////////////////////////////////////////////////////////////////////////////////

//Operadores aritmeticos y de asignación entre monomios

Monomio & Monomio::operator+=(Monomio const &monomio) {
	if(monomio.getGrado() == this->getGrado()) {
		this->setCoeficiente(this->getCoeficiente() + monomio.getCoeficiente());
	}
	//Se devuelve el objeto actual
	return *this;
}

Monomio & Monomio::operator-=(Monomio const &monomio) {
	if(monomio.getGrado() == this->getGrado()) {
		this->setCoeficiente(this->getCoeficiente() - monomio.getCoeficiente());
	}
	//Se devuelve el objeto actual
	return *this;
}

Monomio & Monomio::operator*=(Monomio const &monomio) {
	this->setCoeficiente(this->getCoeficiente() * monomio.getCoeficiente());
	this->setGrado(this->getGrado() + monomio.getGrado());
	//Se devuelve el objeto actual
	return *this;
}

Monomio & Monomio::operator/=(Monomio const &monomio) {
	if((monomio.getGrado() <= this->getGrado()) && !((abs(monomio.getCoeficiente() - 0.0)) < COTA_ERROR)) {
		this->setGrado(this->getGrado() - monomio.getGrado());
		this->setCoeficiente(this->getCoeficiente() / monomio.getCoeficiente());
	}
	//Se devuelve el objeto actual
	return *this;
}

//Operadores aritmeticos y de asignación con reales

Monomio & Monomio::operator*=(double numero_real) {
	setCoeficiente(getCoeficiente() * numero_real);
	//Se devuelve el objeto actual
	return *this;
}

Monomio & Monomio::operator/=(double numero_real) {
	if(!((abs(numero_real - 0.0)) < COTA_ERROR)) {
		setCoeficiente(getCoeficiente() / numero_real);
	}
	//Se devuelve el objeto actual
	return *this;
}

///////////////////////////////////////////////////////////////////////////////////

// Funciones lectura y escritura de la clase Monomio

void Monomio::leerMonomio() {
	double coeficiente_auxiliar;
	int grado_auxiliar;

	cout << "Introduce los valores del monomio:" << endl;
	cout << "\tCoeficiente: ";
	cin >> coeficiente_auxiliar;
	cout << "\tGrado (mayor o igual a 0): ";
	cin >> grado_auxiliar;
	//Se asegura de que el grado introducido no sea negativo
	while(grado_auxiliar < 0){
		cout << "Introduzca un grado mayor o igual a 0: ";
		cin >> grado_auxiliar;
	}
	//Se guardan los valores
	setCoeficiente(coeficiente_auxiliar);
	setGrado(grado_auxiliar);
	//Se limpia el buffer
	std::cin.ignore();
}

void Monomio::escribirMonomio() {
	if(abs(getCoeficiente() - 0.0) < COTA_ERROR) cout << 0;
	else if(getGrado() > 1){
		if(abs(getCoeficiente() - (1.0)) < COTA_ERROR) cout << "X";
		else if(abs(getCoeficiente() - (-1.0)) < COTA_ERROR) cout << "-X";
		else cout << getCoeficiente() << "X";
		cout << "^" << getGrado();
	}
	else if(getGrado() == 1) {
		if(abs(getCoeficiente() - (1.0)) < COTA_ERROR) cout << "X";
		else if(abs(getCoeficiente() - (-1.0)) < COTA_ERROR) cout << "-X";
		else cout << getCoeficiente() << "X";
	}
	else cout << getCoeficiente();
	//Se tiene que escribir el grado
	//Si no se tiene escribir, se añade el salto de linea necesarios
}

///////////////////////////////////////////////////////////////////////////////////

// Funciones auxiliares de la clase Monomio
double Monomio::calcularValor(double numero_real) {
	double resultado;

	resultado = getCoeficiente() * pow(numero_real, getGrado());

	return resultado;
}