//FILE PROVIDED BY UNIVERSITY

/*! 
	\file Monomio.hpp
	\brief Definición de la clase Monomio
	\author Pablo Rodriguez Guillen
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
			float coeficiente_; //!< Coeficiente del monomio
			int grado_; //!< Grado del monomio
		
		//! \name Funciones o métodos públicos de la clase Monomio
		public:
			//! \name Constructores de la clase Monomio

			/*!
				\brief Constructor que crea un monomio a partir de un coeficiente y un grado
				\warning Los parametros tienen valores por defecto
				\param coeficiente: Coeficiente a establecer para el monomio
				\param grado: Grado a establecer para el monomio
				\pre El grado debe ser mayor o igual que 0
				\post Se establecen valores para el coeficiente y el grado del monomio
				\sa setCoeficiente(), setGrado()
			*/
			Monomio(float coeficiente = 0.0, int grado = 0);

			//! \name Observadores: funciones de consulta de la clase Monomio

			/*!
				\brief Observador del coeficiente del monomio
				\note Funcion inline
				\return Coeficiente del monomio (float)
				\sa getGrado
			*/
			inline float getCoeficiente() const {return coeficiente_;}
			/*!
				\brief Observador del grado del monomio
				\note Funcion inline
				\return Grado del monomio (int)
				\sa getCoeficiente
			*/
			inline int getGrado() const {return grado_;}
			
			//! \name Funciones de modificación de la clase Monomio

			/*!
				\brief Modifica el coeficiente del monomio que lo invoca
				\note Funcion inline
				\param new_coeficiente: Coeficiente a establecer
				\sa setGrado
			*/
			inline void setCoeficiente(float new_coeficiente) {coeficiente_ = new_coeficiente;}
			/*!
				\brief Modifica el grado del monomio que invoca el método
				\note Funcion inline
				\param new_grado: Grado a establecer
				\pre El grado a establecer debe ser mayor o igual a 0
				\post El nuevo grado se establece, si new_grado es negativo, se mantiene el grado anterior
			*/
			inline void setGrado(int new_grado) {(new_grado >= 0) ? grado_ = new_grado : grado_ = grado_;}

		/////////////////////////////////////////////////

		//! \name Operadores de la clase Monomio

		// Operadores de asignación

			// COMPLETAR LOS COMENTARIOS DE DOXYGEN
			Monomio & operator=(Monomio const &m);

			// COMPLETAR LOS COMENTARIOS DE DOXYGEN
			Monomio & operator=(double const &x);


		// Operadores aritméticos y asignación

			// COMPLETAR LOS COMENTARIOS DE DOXYGEN
			Monomio & operator+=(Monomio const &m);


			// COMPLETAR EL RESTO DE OPERADORES


		/////////////////////////////////////////////////////////////////////////////////////

		//! \name Funciones lectura y escritura de la clase Monomio

		// COMPLETAR


		///////////////////////////////////////////////////////////////////////

		//! \name Funciones auxiliares de la clase Monomio

		// COMPLETAR



	};  // Fin de la definición de la clase Monomio

}  //  Fin de namespace ed.

// _MONOMIO_HPP_
#endif
