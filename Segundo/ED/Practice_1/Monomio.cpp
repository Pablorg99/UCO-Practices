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
using std::to_string;

#include "Monomio.hpp"

//Constructores

ed::Monomio::Monomio(double coeficiente, int grado) {
	setCoeficiente(coeficiente);
	setGrado(grado);
}

///////////////////////////////////////////////////////////////////////////////////

//Operadores de asignación

/*
ed::Monomio & ed::Monomio::operator=(ed::Monomio const &m)
{
	
	// Se devuelve el objeto actual
	return *this;
}
*/

ed::Monomio ed::Monomio::operator=(double const numero_real) {
	setGrado(0);
	setCoeficiente(numero_real);
	// Se devuelve el objeto actual
	return *this;
}

///////////////////////////////////////////////////////////////////////////////////

//Operadores aritmeticos y de asignación entre monomios

ed::Monomio ed::Monomio::operator+=(Monomio const &monomio) {
	if(monomio.getGrado() == this->getGrado()) {
		this->setCoeficiente(this->getCoeficiente() + monomio.getCoeficiente());
	}
	//Se devuelve el objeto actual
	return *this;
}

ed::Monomio ed::Monomio::operator-=(Monomio const &monomio) {
	if(monomio.getGrado() == this->getGrado()) {
		this->setCoeficiente(this->getCoeficiente() - monomio.getCoeficiente());
	}
	//Se devuelve el objeto actual
	return *this;
}

ed::Monomio ed::Monomio::operator*=(Monomio const &monomio) {
	this->setCoeficiente(this->getCoeficiente() * monomio.getCoeficiente());
	this->setGrado(this->getGrado() + monomio.getGrado());
	//Se devuelve el objeto actual
	return *this;
}

ed::Monomio ed::Monomio::operator/=(Monomio const &monomio) {
	if((monomio.getGrado() <= this->getGrado()) && !((abs(monomio.getCoeficiente() - 0.0)) < COTA_ERROR)) {
		this->setGrado(this->getGrado() - monomio.getGrado());
		this->setCoeficiente(this->getCoeficiente() / monomio.getCoeficiente());
	}
	//Se devuelve el objeto actual
	return *this;
}

//Operadores aritmeticos y de asignación con reales

ed::Monomio ed::Monomio::operator*=(double numero_real) {
	setCoeficiente(getCoeficiente() * numero_real);
	//Se devuelve el objeto actual
	return *this;
}

ed::Monomio ed::Monomio::operator/=(double numero_real) {
	if(!((abs(numero_real - 0.0)) < COTA_ERROR)) {
		setCoeficiente(getCoeficiente() / numero_real);
	}
	//Se devuelve el objeto actual
	return *this;
}

///////////////////////////////////////////////////////////////////////////////////

// Funciones lectura y escritura de la clase Monomio

void ed::Monomio::leerMonomio() {
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

	setCoeficiente(coeficiente_auxiliar);
	setGrado(grado_auxiliar);
}

void ed::Monomio::escribirMonomio() {
	string coeficiente;
	string grado;

	//Formateo excepcional
	if((getGrado() == 0) && ((abs(getCoeficiente() - (1.0)) < COTA_ERROR))) cout << "Monomio: 1" << endl;
	else if((getGrado() == 0) && ((abs(getCoeficiente() - (-1.0)) < COTA_ERROR))) cout << "Monomio: -1" << endl;
	else {
		//Formateo del coeficiente
		if((abs(getCoeficiente() - (1.0)) < COTA_ERROR)) coeficiente = "";
		else if((abs(getCoeficiente() - (-1.0)) < COTA_ERROR)) coeficiente = "-";
		else coeficiente = to_string(getCoeficiente());
		//Formateo del grado	
		if(getGrado() == 0) grado = "";
		else if(getGrado() == 1) grado = "X";
		else grado = "X^" + to_string(getGrado());

		cout << "Monomio: " << coeficiente << grado << endl;
	}
}

///////////////////////////////////////////////////////////////////////////////////

// Funciones auxiliares de la clase Monomio
double ed::Monomio::calcularValor(double numero_real) {
	double resultado;

	resultado = getCoeficiente() * pow(numero_real, getGrado());

	return resultado;
}

