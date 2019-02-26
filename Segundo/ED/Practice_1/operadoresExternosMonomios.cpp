//FILE PROVIDED BY UNIVERSITY

/*! 
   \file  operadoresExternosMonomios.cpp
	\brief Ficheros con el código de los operadores externos de la clase Monomio
*/


//  Ficheros de cabecera
#include <iostream>

#include "operadoresExternosMonomios.hpp"


//  Se incluyen los operadores sobrecargados dentro del espacio de nombres ed
namespace ed 
{
	// Operadores de igualdad
	bool operator==(ed::Monomio const & monomio_1, ed::Monomio const & monomio_2) {
		//Booleanos locales para ver si se cumplen igualdades
		bool equalGrado = monomio_1.getGrado() == monomio_2.getGrado();
		bool equalCoeficiente = (abs(monomio_1.getCoeficiente() - monomio_2.getCoeficiente()) < COTA_ERROR);
		if(equalGrado && equalCoeficiente)	return true;
		else return false;
	}

	bool operator==(ed::Monomio const & monomio, double numero_real) {
		if(monomio.getGrado() == 0 && (abs(monomio.getCoeficiente() - numero_real) < COTA_ERROR)) return true;
		else return false;
	}

	bool operator==(double numero_real, ed::Monomio const & monomio) {
		if(monomio == numero_real) return true;
		else return false;
	}

	// Operadores de desigualdad
	bool operator!=(ed::Monomio const & monomio_1, Monomio const & monomio_2) {
		if(monomio_1 == monomio_2) return false;
		else return true;
	}

	bool operator!=(ed::Monomio const & monomio, double numero_real) {
		if(monomio == numero_real) return false;
		else return true;
	}

	bool operator!=(double numero_real, ed::Monomio const & monomio) {
		if(monomio != numero_real) return true;
		else return false;
	}

	// Operadores unarios prefijos 

	Monomio & operator+(Monomio const & monomio) {
		Monomio *new_monomio = new Monomio(monomio.getCoeficiente(), monomio.getGrado());
		return *new_monomio;
	}

	Monomio & operator-(Monomio const & monomio) {
		Monomio *new_monomio = new Monomio((-1 * monomio.getCoeficiente()), monomio.getGrado());
		return *new_monomio;
	}

	// Operadores aritméticos binarios

	// Suma
	Monomio & operator+(Monomio const &monomio_1, Monomio const &monomio_2) {
		#ifndef NDEBUG
			assert(monomio_1.getGrado() != monomio_2.getGrado());
		#endif
		// Se crea un nuevo objeto
		Monomio *new_monomio = new Monomio(monomio_1.getCoeficiente() + monomio_2.getCoeficiente(), monomio_1.getGrado());
		// Se devuelve el resultado
		return *new_monomio;
	}

	// Resta
	Monomio & operator-(Monomio const &monomio_1, Monomio const &monomio_2) {
		#ifndef NDEBUG
			assert(monomio_1.getGrado() != monomio_2.getGrado());
		#endif
		// Se crea un nuevo objeto
		Monomio *new_monomio = new Monomio(monomio_1.getCoeficiente() - monomio_2.getCoeficiente(), monomio_1.getGrado());
		// Se devuelve el resultado
		return *new_monomio;
	}

	// Multiplicación
	Monomio operator*(Monomio const &monomio_1, Monomio const &monomio_2) {
		int new_grado = monomio_1.getGrado() + monomio_2.getGrado();
		double new_coeficiente = monomio_1.getCoeficiente() * monomio_2.getCoeficiente();
		//Se crea un nuevo objeto
		Monomio *new_monomio = new Monomio(new_coeficiente, new_grado);
		//Se devuelve el resultado
		return *new_monomio;
	}

	Monomio & operator*(Monomio const &monomio, double numero_real) {
		//Se crea un nuevo objeto
		Monomio *new_monomio = new Monomio(monomio.getCoeficiente() * numero_real, monomio.getGrado());
		//Se devuelve el resultado
		return *new_monomio;
	}
	
	Monomio & operator*(double numero_real, Monomio const &monomio) {
		//Se crea un nuevo objeto
		Monomio *new_monomio = &(monomio * numero_real);
		//Se devuelve el resultado
		return *new_monomio;
	}
	
	// División
	Monomio & operator/(Monomio const &monomio_1, Monomio const &monomio_2) {
		#ifndef NDEBUG
			assert(monomio_1.getGrado() < monomio_2.getGrado());
			assert(abs(monomio_2.getCoeficiente() - 0.0) < COTA_ERROR);
		#endif
		int new_grado = monomio_1.getGrado() - monomio_2.getGrado();
		double new_coeficiente = monomio_1.getCoeficiente() / monomio_2.getCoeficiente();
		//Se crea un nuevo objeto
		Monomio *new_monomio = new Monomio(new_coeficiente, new_grado);
		//Se devuelve el resultado
		return *new_monomio;
	}

	Monomio & operator/(double numero_real, Monomio const &monomio) {
		#ifndef NDEBUG
			assert(abs(monomio.getCoeficiente() - 0.0) < COTA_ERROR);
			assert(monomio.getGrado() != 0);
		#endif
		//Se crea un nuevo objeto
		Monomio *new_monomio = new Monomio(numero_real / monomio.getCoeficiente(), monomio.getGrado());
		//Se devuelve el resultado
		return *new_monomio;
	}

	Monomio & operator/(Monomio const &monomio, double numero_real) {
		#ifndef NDEBUG
			assert(numero_real == 0);
		#endif
		//Se crea un nuevo objeto
		Monomio *new_monomio = new Monomio(monomio.getCoeficiente() / numero_real, monomio.getGrado());
		//Se devuelve el resultado
		return *new_monomio;
	}

	//  Sobrecarga del operador de entrada
	istream &operator>>(istream &stream, Monomio &monomio) {
		string cadena_auxiliar;
		getline(stream, cadena_auxiliar, ' ');
		monomio.setCoeficiente(atof(cadena_auxiliar.c_str()));
		getline(stream, cadena_auxiliar); //El valor por defecto de separacion es \n
		monomio.setGrado(atoi(cadena_auxiliar.c_str()));
		//Se limpia el buffer
		std::cin.ignore();
   		// Se devuelve el flujo de entrada
		return stream;
	}


	//  Sobrecarga del operador de salida
	ostream &operator<<(ostream &stream, Monomio const &monomio) {
		stream << monomio.getCoeficiente() << " " << monomio.getGrado();
		// Se devuelve el flujo de salida
		return stream;
	}
} // namespace ed
