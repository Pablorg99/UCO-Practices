/**
 * @file operadoresExternosPolinomios.hpp
 * @author Pablo Rodríguez Guillén (i72rogup@uco.es)
 * @brief Fichero de implemantació de los operadores externos de la clase polinomio
 * @version 0.1
 * @date 2019-31-03
 * @copyright Copyright (c) 2019
 */


// Ficheros de cabecera
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include "operadoresExternosPolinomios.hpp"

#include "operadoresExternosMonomios.hpp"

// Se incluyen los operadores sobrecargados dentro del espacio de nombres de ed

namespace ed
{

//Operadores de igualdad

bool operator==(Polinomio const & polinomio1, Polinomio const & polinomio2) {
	vector <Monomio>::const_iterator monomio1 = polinomio1.getVector().begin();
	vector <Monomio>::const_iterator monomio2 = polinomio2.getVector().begin();
	if(polinomio1.getNumeroMonomios() != polinomio2.getNumeroMonomios()) return false;
	else {
		while((monomio1 != polinomio1.getVector().end()) && monomio2 != polinomio2.getVector().end()) {
			if(monomio1 != monomio2) return false;
		}
	}
	return true;
	
}

bool operator==(Polinomio const &polinomio, Monomio const & monomio) {
	if(polinomio.getNumeroMonomios() != 1) return false;
	else if(polinomio.getVector().front() != monomio) return false;
	else return true;
}

bool operator==(Monomio const & monomio, Polinomio const &polinomio) {
	return polinomio == monomio;
}

bool operator==(Polinomio const &polinomio, double numero_real) {
	vector <Monomio>::const_iterator monomio;
	if(polinomio.getNumeroMonomios() != 1) return false;
	else if(polinomio.getVector().front() != numero_real) return false;
	else return true;
}

bool operator==(double numero_real, Polinomio const &polinomio) {
	return polinomio == numero_real;
}

//////////////////////////////////////////////////////////////////////////////////////

//Operadores de desigualdad

bool operator!=(Polinomio const & polinomio1, Polinomio const & polinomio2) {
	return !(polinomio1 == polinomio2);
}

bool operator!=(Polinomio const & polinomio, Monomio const & monomio) {
	return !(polinomio == monomio);
}

bool operator!=(Monomio const & monomio, Polinomio const & polinomio) {
	return !(polinomio == monomio);
}

bool operator!=(Polinomio const & polinomio, double numero_real) {
	return !(polinomio == numero_real);
}

bool operator!=(double numero_real, Polinomio const & polinomio) {
	return !(polinomio == numero_real);
}

//////////////////////////////////////////////////////////////////////////////////////

//Operadores unarios

Polinomio & operator+(Polinomio const & polinomio) {
	Polinomio *return_polinomio = new Polinomio(polinomio);
	return *return_polinomio;
}

Polinomio & operator-(Polinomio const & polinomio) {
	vector <Monomio> new_vector = polinomio.getVector();
	int index = 0;
	vector <Monomio>::const_iterator monomio;
	for(monomio = polinomio.getVector().begin(); monomio != polinomio.getVector().end(); monomio++) {
		new_vector.assign(index, -(*monomio));
		index++;
	}
	Polinomio new_polinomio;
	new_polinomio.setVector(new_vector);
	Polinomio *return_polinomio = new Polinomio(new_polinomio);
	return *return_polinomio;
}

//////////////////////////////////////////////////////////////////////////////////////

//OPERADORES BINARIOS

//Operador suma

Polinomio & operator+(Polinomio const &polinomio1,  Polinomio const &polinomio2) {
	Polinomio new_polinomio;
	vector <Monomio>::const_iterator monomio1;
	for(monomio1 = polinomio1.getVector().begin(); monomio1 != polinomio1.getVector().end(); monomio1++) {
		new_polinomio = polinomio2 + *monomio1;
	}
	Polinomio *return_polinomio = new Polinomio(new_polinomio);
	return *return_polinomio;
}

Polinomio & operator+(Polinomio const &polinomio, Monomio const & monomio) {
	vector <Monomio> new_vector = polinomio.getVector();
	int index = 0;
	vector <Monomio>::const_iterator monomio_it;
	bool sumado = false;
	for(monomio_it = polinomio.getVector().begin(); monomio_it != polinomio.getVector().end(); monomio_it++) {
		if(monomio_it->getGrado() == monomio.getGrado()) {
			new_vector.assign(index, *monomio_it + monomio);
			sumado = true;
		}
		index++;
	}
	if(sumado == false) new_vector.push_back(monomio);
	Polinomio new_polinomio;
	new_polinomio.setVector(new_vector);
	Polinomio *return_polinomio = new Polinomio(new_polinomio);
	return *return_polinomio;
}

Polinomio & operator+(Monomio const & monomio, Polinomio const &polinomio) {
	Polinomio *return_polinomio = new Polinomio(polinomio + monomio);
	return *return_polinomio;
}

Polinomio & operator+(Polinomio const &polinomio, double numero_real) {
	Monomio monomio_aux(0, numero_real);
	Polinomio *return_polinomio = new Polinomio(polinomio + monomio_aux);
	return *return_polinomio;
}

Polinomio & operator+(double numero_real, Polinomio const &polinomio) {
	Monomio monomio_aux(0, numero_real);
	Polinomio *return_polinomio = new Polinomio(polinomio + monomio_aux);
	return *return_polinomio;
}

//Operador resta

Polinomio & operator-(Polinomio const &polinomio1,  Polinomio const &polinomio2) {
	Polinomio *return_polinomio = new Polinomio(polinomio1 + (-polinomio2));
	return *return_polinomio;
}

Polinomio & operator-(Polinomio const &polinomio, Monomio const & monomio) {
	Polinomio *return_polinomio = new Polinomio(polinomio + (-monomio));
	return *return_polinomio;
}

Polinomio & operator-(Monomio const & monomio, Polinomio const &polinomio) {
	Polinomio *return_polinomio = new Polinomio(polinomio - monomio);
	return *return_polinomio;
}

Polinomio & operator-(Polinomio const &polinomio, double numero_real) {
	Monomio monomio_aux(0, numero_real);
	Polinomio *return_polinomio = new Polinomio(polinomio - monomio_aux);
	return *return_polinomio;
}

Polinomio & operator-(double numero_real, Polinomio const &polinomio) {
	Monomio monomio_aux(0, numero_real);
	Polinomio *return_polinomio = new Polinomio(polinomio - monomio_aux);
	return *return_polinomio;
}

//Operador multiplicación

Polinomio & operator*(Polinomio const &polinomio1,  Polinomio const &polinomio2) {
	Polinomio new_polinomio;
	vector <Monomio>::const_iterator monomio1;
	for(monomio1 = polinomio1.getVector().begin(); monomio1 != polinomio1.getVector().end(); monomio1++) {
		new_polinomio = polinomio2 * (*monomio1);
	}
	Polinomio *return_polinomio = new Polinomio(new_polinomio);
	return *return_polinomio;
}

Polinomio & operator*(Polinomio const &polinomio, Monomio const & monomio) {
	vector <Monomio> new_vector = polinomio.getVector();
	int index = 0;
	vector <Monomio>::const_iterator monomio_it;
	for(monomio_it = polinomio.getVector().begin(); monomio_it != polinomio.getVector().end(); monomio_it++) {
		new_vector.assign(index, *monomio_it * monomio);
		index++;
	}
	Polinomio new_polinomio;
	new_polinomio.setVector(new_vector);
	Polinomio *return_polinomio = new Polinomio(new_polinomio);
	return *return_polinomio;
}

Polinomio & operator*(Monomio const & monomio, Polinomio const &polinomio) {
	Polinomio *return_polinomio = new Polinomio(polinomio * monomio);
	return *return_polinomio;
}

Polinomio & operator*(Polinomio const &polinomio, double numero_real) {
	Monomio monomio_aux(0, numero_real);
	Polinomio *return_polinomio = new Polinomio(polinomio * monomio_aux);
	return *return_polinomio;
}

Polinomio & operator*(double numero_real, Polinomio const &polinomio) {
	Monomio monomio_aux(0, numero_real);
	Polinomio *return_polinomio = new Polinomio(polinomio * monomio_aux);
	return *return_polinomio;
}

//Operador división

Polinomio & operator/(Polinomio const &polinomio1,  Polinomio const &polinomio2) {
	Polinomio *return_polinomio = new Polinomio();
	return *return_polinomio;
}

Polinomio & operator/(Polinomio const &polinomio, Monomio const & monomio) {
	Polinomio *return_polinomio = new Polinomio();
	return *return_polinomio;
}

Polinomio & operator/(Monomio const & monomio, Polinomio const &polinomio) {
	Polinomio *return_polinomio = new Polinomio();
	return *return_polinomio;
}

Polinomio & operator/(Polinomio const &polinomio, double numero_real) {
	Polinomio *return_polinomio = new Polinomio();
	return *return_polinomio;
}

Polinomio & operator/(double numero_real, Polinomio const &polinomio) {
	Polinomio *return_polinomio = new Polinomio();
	return *return_polinomio;
}

//////////////////////////////////////////////////////////////////////////////////////

//Operadores de flujo

ostream &operator<<(ostream &stream, Polinomio const &polinomio) {
	vector <Monomio>::const_iterator monomio;
	for(monomio = polinomio.getVector().begin(); monomio != polinomio.getVector().end(); monomio++) {
		stream << *monomio << " ";
	}
	return stream;
}

istream &operator>>(istream &stream, Polinomio &polinomio) {
	return stream;
}

} // Fin del espacio de nombres ed
