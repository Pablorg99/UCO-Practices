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
	_getVector().push_back(monomio);
}

Polinomio::Polinomio(const Polinomio &polinomio) {
	_vectorMonomios = polinomio._getVector();
}

//Observadores

bool Polinomio::esNulo() const {
	if((getNumeroMonomios() == 1) && (_getVector().front().esNulo())) return true;
	else return false;
}

bool Polinomio::existeMonomio(int grado_monomio) const {
	vector <Monomio>::const_iterator monomio;
	for(monomio = _getVector().begin(); monomio != _getVector().end(); monomio++) {
		if(monomio->getGrado() == grado_monomio) return true;
	}
	return false;
}

Monomio Polinomio::getMonomio(int grado_monomio) const {
	Monomio monomio_nulo;
	if(existeMonomio(grado_monomio)) {
		vector <Monomio>::const_iterator monomio;
		for(monomio = _getVector().begin(); monomio != _getVector().end(); monomio++) {
			if(monomio->getGrado() == grado_monomio) return *monomio;
		}
	}
	else return monomio_nulo;
}

bool Polinomio::_estaOrdenado() const {
	vector <Monomio>::const_iterator monomio;
	for(monomio = _getVector().begin(); monomio != _getVector().end(); monomio++) {
		if((monomio - 1)->getGrado() < monomio->getGrado()) return false;
	}
	return true;
}

//Modificadores

void Polinomio::_ordenaPolinomio() {
	if (_estaOrdenado() == false) {
		int low = 0;
		int high = _getVector().size() - 1;
		_quickSort(_vectorMonomios, low, high);
		#ifndef NDEBUG
			assert(!_estaOrdenado());
		#endif
	}
}

//Funciones privadas

void _swap(Monomio &monomio1, Monomio &monomio2) { 
    Monomio monomio_auxiliar;
    monomio_auxiliar = monomio1;
	monomio1 = monomio2;
	monomio2 = monomio_auxiliar;
} 

int _partition (vector <Monomio> &array, int low, int high) { 
    // Valor del pivote
	int pivot = array[high].getGrado();
    // Indice del elemento mayor
	int i = (low - 1);
  
    for (int j = low; j <= high - 1; j++) { 
        // Si el elemento actual es menor o igual que el pivote 
        if (array[j].getGrado() >= pivot) { 
            // Incremento del índice del elemento mayor
			i++;
			//Se ingercambian los elementos
            _swap(array[i], array[j]); 
        } 
    } 
    _swap(array[i + 1], array[high]); 
    return (i + 1); 
} 
  
void _quickSort(vector <Monomio> &array, int low, int high) { 
    if (low < high) { 
        //Índice de la partición, array[partition_index] está en la posición correcta
        int partition_index = _partition(array, low, high); 
        //Ordena de forma separada los elementos anteriores y posteriores a la partición (pivote)
        _quickSort(array, low, partition_index - 1); 
        _quickSort(array, partition_index + 1, high); 
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
	this->_getVector().clear();
	//Añado el monomio al vector de monomios del polinomio y devuelvo el objeto
	this->_getVector().assign(0, monomio);
	return *this;
}


Polinomio & Polinomio::operator=(double const &numero_real) {
	//Creo un monomio con coeficiente = numero_real y grado = 0
	Monomio monomio(0, numero_real);
	//Limpio el vector del polinomio y le añado unicamente el monomio creado
	this->_getVector().clear();
	this->_getVector().assign(0, monomio);
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
	for(int i = 0; i < numero_monomios; i++) {
		cout << "-----------------" << endl;
		_getVector().at(i).leerMonomio();
		cout << "-----------------" << endl;
	}
	_ordenaPolinomio();
}

void Polinomio::escribirPolinomio() {
	vector <Monomio>::iterator monomio;
	for(monomio = _getVector().begin(); monomio != _getVector().end(); monomio++) {
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
	for(monomio = _getVector().begin(); monomio != _getVector().end(); monomio++) {
		resultado += monomio->calcularValor(numero_real);
	}
	return resultado;
}

