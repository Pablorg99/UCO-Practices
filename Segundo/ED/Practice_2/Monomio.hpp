//FILE PROVIDED BY UNIVERSITY

/*! 
	\file Monomio.hpp
	\brief Definición de la clase Monomio
	\author Pablo Rodríguez Guillén
*/

#ifndef _MONOMIO_HPP_
#define _MONOMIO_HPP_

// Para usar la funciones pow y std::abs
#include <cmath>
using std::abs;

// Para controlar las pre y post condiciones mediante asertos
#include <cassert>

#define COTA_ERROR 1.0e-6  //!< Cota de error para la comparación números reales

// Se incluye la clase Monomio dentro del espacio de nombre de la asigantura: ed
namespace ed
{
	//!  Definición de la clase Monomio:  \f$ coeficiente \hspace{1ex} X^{grado} \f$ 
	class Monomio
	{
		//!\name Atributos privados de la clase Monomio
		private:
			double coeficiente_; //!< Coeficiente del monomio
			int grado_; //!< Grado del monomio
		
		//! \name Métodos publicos de la clase Monomio
		public:
			//! \name Constructores de la clase Monomio

			/*!
				\brief Constructor que crea un monomio a partir de un coeficiente y un grado
				\param coeficiente: Coeficiente a establecer para el monomio
				\param grado: Grado a establecer para el monomio
				\note Función sobrecargada
				\warning Los parámetros tienen valores por defecto
				\pre El grado debe ser mayor o igual que 0
				\post Se establecen valores para el coeficiente y el grado del monomio
				\sa setCoeficiente(), setGrado()
			*/
			Monomio(double coeficiente = 0.0, int grado = 0);

			/*!
				\brief Constructor de copia que copia campo a campo
				\param monomio: Referencia constante al monomio pasado como argumento
				\warning Los parámetros tienen valores por defecto
				\pre El grado debe ser mayor o igual que 0
				\post Se establecen los mismos valores de coeficiente y grado al objeto que invoca el constructor
				\sa setCoeficiente(), setGrado()
			*/
			Monomio(Monomio const &monomio);

			//! \name Observadores: funciones de consulta de la clase Monomio

			/*!
				\brief Observador del coeficiente del monomio
				\note Función inline
				\return Coeficiente del monomio (double)
				\sa getGrado
			*/
			inline double getCoeficiente() const {return coeficiente_;}

			/*!
				\brief Observador del grado del monomio
				\note Función inline
				\return Grado del monomio (int)
				\sa getCoeficiente
			*/
			inline int getGrado() const {return grado_;}

			bool esNulo() const;
			
			//! \name Funciones de modificación de la clase Monomio

			/*!
				\brief Modifica el coeficiente del monomio que lo invoca
				\note Función inline
				\param new_coeficiente: Coeficiente a establecer
				\sa setGrado
			*/
			inline void setCoeficiente(double new_coeficiente) {coeficiente_ = new_coeficiente;}

			/*!
				\brief Modifica el grado del monomio que invoca el método
				\note Función inline
				\param new_grado: Grado a establecer
				\pre El grado a establecer debe ser mayor o igual a 0
				\post El nuevo grado se establece, si new_grado es negativo, se mantiene el grado anterior
			*/
			inline void setGrado(int new_grado) {new_grado >= 0 ? grado_ = new_grado : grado_ = grado_;}


			//! \name Operadores de la clase Monomio

			/*!
				\breif Implementación del operador de asignación por defecto
				\param monomio: Referencia constante al objeto a la izquierda del operador
				\note Función sobrecargada
				\return Monomio que invoca el operador
			*/
			Monomio & operator=(Monomio const &monomio);

			/*!
				\brief Establece el grado a 0 y el coeficiente al flotante al que se iguala el monomio
				\param numero_real: Nuevo coeficiente del monomio
				\note Función sobrecargada
				\return Monomio sometido a la operación
			*/
			Monomio & operator=(double const numero_real);

			/*!
				\brief Implementación del operador += para 2 monomios
				\param monomio: Referencia al monomio que se suma al monomio que invoca el operador
				\pre Ambos monomios tienen el mismo grado
				\return Monomio resultante de la operación
				\post El monomio devuelto tiene como coeficiente la suma de los coeficientes de ambos monomios y el grado comun a ambos
			*/
			Monomio & operator+=(Monomio const &monomio);

			/*!
				\brief Implementación del operando -= para 2 monomios
				\param monomio: Referencia al monomio que se resta al que invoca el operador
				\pre Ambos monomios tienen el mismo grado
				\return Monomio resultante de la operación
				\post El coeficiente del monomio devuelto es la resta de ambos coeficientes. El grado es el comun a ambos
			*/
			Monomio & operator-=(Monomio const &monomio);

			/*!
				\brief Implementación del operador *= para 2 monomios
				\param monomio: Referencia al monomio que multiplica al que invoca el operador
				\return Monomio resultante de la operación
				\post El coeficiente del monomio original se multiplica con el del pasado por referencia. 
					  El grado resultante es la suma del grado de ambos.
			*/
			Monomio & operator*=(Monomio const &monomio);

			/*!
				\brief Implementación del operador /= para 2 monomios
				\note Función sobrecargada
				\param monomio: Referencia al monomio que divide al que invoca el operador
				\pre El grado del monomio pasado por referencia es menor o igual que el del monomio actual
					 El coeficiente del monomio pasado por referencia no es 0
				\return Monomio resultante de la operación
				\post El coeficiente del monomio original se divide entre el del pasado por referencia. 
					  El grado resultante es la resta del grado de ambos. 
			*/
			Monomio & operator/=(Monomio const &monomio);

			/*!
				\brief Implementación del operador *= de un monomio con un real
				\note Función sobrecargada
				\param numero_real: Numero que multiplica al monomio actual
				\return monomio resultante de la operación
				\post El coeficiente del monomio se multiplica por el numero pasado mientras que el grado permanece invariado
			*/
			Monomio & operator*=(double numero_real);

			/*!
				\brief Implementación del operador /= de un monomio con un real
				\note Función sobrecargada
				\param numero_real: Numero que divide al monomio actual
				\pre El numero real no es 0.0
				\return monomio resultante de la operación
				\post El coeficiente del monomio se divide entre el numero pasado mientras que el grado permanece invariado
			*/
			Monomio & operator/=(double numero_real);

			//! \name Funciones lectura y escritura de la clase Monomio

			/*!
				\brief Pide al usuario que introduce los valores del monomio por teclado
				\post El grado es mayor o igual que 0
			*/
			void leerMonomio();

			/*!
				\brief Imprime el monomio por pantalla con un formato
				\note Formato: Coeficiente X^grado || Coeficiente 1: X^grado || Coeficiente -1: -X^grado || Grado 0: Coeficiente || Grado 1: X (sin grado)
			*/
			void escribirMonomio() const;

			//! \name Funciones auxiliares de la clase Monomio

			/*!
				\brief Calcula el valor del monomio para un valor de X
				\param numero_real: Numero por el que sustituir la X para operar
				\return El numero real que resulta de operar el monomio
			*/
			double calcularValor(double numero_real);
	}; // Fin de la definición de la clase Monomio

} //  Fin de namespace ed.

#endif // _MONOMIO_HPP_
