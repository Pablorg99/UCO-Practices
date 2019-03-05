/*!
 \mainpage Implementación de un Polinomio
 \brief		\f$ P(X) = a_n X^n + a_{n-1} X^n-1} \cdots + a_2 X^2 + a_1 X + a_0 \f$
 \author   
 \date     
 \version  1.0
*/

/*!

	\file principal.cpp
	\brief Programa principal de la practica 2 de ED: polinomios
*/

#include <iostream>

#include "funcionesAuxiliares.hpp"

#include "macros.hpp"

/*! 
	\brief   Función principal de la práctica 2: polinomios
	\return  int
*/
int main()
{
	int opcion;

	do{

		// Se elige la opción del menún
		opcion = ed::menu();		

		std::cout << CLEAR_SCREEN;
		PLACE(3,1);

		// Se ejecuta la opción del menú elegida
		switch(opcion)
		{
			case 0: 
				PLACE(3,1);
				std::cout << BRED;
				std::cout << "[0] Fin del programa" << std::endl << std::endl;
				std::cout << RESET;
				break;

			case 1: 
			   	std::cout << BIBLUE;
				std::cout << "[1] Test de la clase Polinomio" << std::endl;
				std::cout << RESET;

				ed::testPolinomio();
				break;

			case 2: 
			   	std::cout << BIBLUE;
				std::cout << "[2] Operadores externos de la clase Polinomio " << std::endl;
				std::cout << RESET;

				ed::operadoresExternosPolinomios();
				break;

			default:
				std::cout << BIRED;
				std::cout << "Opción incorrecta ";
				std::cout << RESET;
				std::cout << "--> ";
			  	std::cout << ONIRED;
				std::cout << opcion << std::endl;
				std::cout << RESET;
     }
  
    if (opcion !=0)
    {
		std::cout << "Para mostrar el ";
		std::cout << BIGREEN ;
		std::cout << "menú, "; 
		std::cout << RESET;
		std::cout << "pulse ";
		std::cout << INVERSE ;
		std::cout << "ENTER";
		std::cout << RESET;

		// Pausa
		std::cin.ignore();

		std::cout << CLEAR_SCREEN;
    }
	  }while(opcion!=0);

	return 0;
}


