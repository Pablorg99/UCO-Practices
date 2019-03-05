/*!
  \file   funcionesAuxiliares.cpp
  \brief  Código de las funciones auxiliares para el programa principal de la práctica 2
  \author
  \date
*/

// Para los flujos de entrada y salida
#include <iostream>
#include <string>

#include "macros.hpp"
#include "funcionesAuxiliares.hpp"

#include "operadoresExternosMonomios.hpp"
#include "operadoresExternosPolinomios.hpp"



int ed::menu()
{
 int opcion, posicion;

	// Se muestran las opciones del menú
	posicion=2;

	// Se borra la pantalla
	std::cout << CLEAR_SCREEN;

	PLACE(posicion++,10);
	std::cout << BIBLUE;
	std::cout << "Programa principal | Opciones del menú   ";
	std::cout << RESET;

	posicion++;
	PLACE(posicion++,10);
	std::cout << "[1] Test de la clase Polinomio" << std::endl;

	PLACE(posicion++,10);
	std::cout << "[2] Operadores externos de la clase Polinomio " << std::endl;

	posicion++;
	PLACE(posicion++,10);
	std::cout << BIRED;
	std::cout << "[0] Fin del programa " << std::endl;
	std::cout << RESET;

	posicion++;
	PLACE(posicion++,10);
	std::cout << BIYELLOW;
	std::cout << "Opción: ";
	std::cout << RESET;
	std::cin >> opcion;

   	// Se elimina el salto de línea del flujo de entrada
    std::cin.ignore();

	return opcion;
}


///////////////////////////////////////////////////////////////////////////
void ed::testPolinomio()
{
  // QUITAR ESTAS SENTENCIAS Y EL COMENTARIO DE BLOQUE
  std::cout << BIGREEN;
  std::cout << "testPolinomio()" << std::endl;
  std::cout << RESET;
  std::cout << "Quitar el comentario de bloque cuando se haya codificado la clase Polinomio " << std::endl << std::endl;

  /*
	double x;

	ed::Monomio m;

	// Constructor sin argumentos
	ed::Polinomio p1, p2;


	// Lectura y escritura de un número real auxilar
	std::cout << BIGREEN;
	std::cout<< "Lectura de un número real auxiliar" << std::endl;
	std::cout << RESET;
	std::cout<< "x = ";
	std::cin >> x;
 	// Se elimina el salto de línea del flujo de entrada
    std::cin.ignore();
	std::cout << std::endl << std::endl;


	// Lectura y escritura de un monomio auxiliar
	std::cout << BIGREEN;
	std::cout<< "Lectura de un monomio auxiliar" << std::endl;
	std::cout << RESET;
	m.leerMonomio();
	std::cout<< "m = ";
	m.escribirMonomio();
	std::cout << std::endl << std::endl;

	// Lectura usando la función de la clase Polinomio
	std::cout << BIGREEN;
	std::cout<< "Lectura del polinomio "<< std::endl << std::endl;
	std::cout << RESET;
	p1.leerPolinomio();
	std::cout << std::endl << std::endl;

	// Constructor de copia
	ed::Polinomio p3(p1);

	//
	// Entre un polinomio y un número
	std::cout << BIGREEN;
	std::cout<< "Escritura de los polinomios"<< std::endl << std::endl;
	std::cout << RESET;

	std::cout<< "p1 = ";
	p1.escribirPolinomio();
	std::cout << std::endl << std::endl;

	std::cout<< "p2 = ";
	p2.escribirPolinomio();
	std::cout << std::endl << std::endl;

	std::cout<< "p3 = ";
	p3.escribirPolinomio();
	std::cout << std::endl << std::endl;

	std::cout << "Para continuar, pulse ";
	std::cout << INVERSE ;
	std::cout << "ENTER";
	std::cout << RESET;

	// Pausa
	std::cin.ignore();


	////////////////////////////////////////////////////////
	// Observadores de la clase Polinomio
	std::cout<< "p1 = ";
	p1.escribirPolinomio();
	std::cout << std::endl << std::endl;

	if (p1.esNulo())
		std::cout << "es un polinomio nulo" << std::endl;
	else
		std::cout << "no es un polinomio nulo" << std::endl;

	std::cout << "grado del polinomio p1: " << p1.getGrado();
	std::cout << std::endl;
	std::cout << "número de monomios del polinomio p1: " << p1.getNumeroMonomios();
	std::cout << std::endl << std::endl;

	for (int i = 0; i <= p1.getGrado(); i++)
	{
		if (p1.existeMonomio(i))
		{
			std::cout << "Monomio de grado " << i << " --> ";
			p1.getMonomio(i).escribirMonomio();
			std::cout << std::endl;
		}
		else
		{
			std::cout << "Monomio de grado " << i << " --> 0.0";
			std::cout << std::endl;
		}
	}

	std::cout << "Para continuar, pulse ";
	std::cout << INVERSE ;
	std::cout << "ENTER";
	std::cout << RESET;
	// Pausa
	std::cin.ignore();


	////////////////////////////////////////////////////////
	// Operadores de asignación

	// Asignación de un monomio a otro monomio
	std::cout << BIGREEN;
	std::cout<< "Operadores de asignación "<< std::endl;
	std::cout << RESET;

	std::cout<< "Operador de asignación de un polinomio a otro polinomio "<< std::endl;
	std::cout<< "p1 = p2"<< std::endl;
	p1 = p2;
	std::cout<< "p1 = ";
	p1.escribirPolinomio();
	std::cout << std::endl;
	std::cout<< "p2 = ";
	p2.escribirPolinomio();
	std::cout << std::endl << std::endl;

	// Asignación de un número a un polinomio
	std::cout<< "Asignación de un monomio a un polinomio --> p1 = m"<< std::endl;
	p1 = m;
	std::cout<< "p1 = ";
	p2.escribirPolinomio();
	std::cout << std::endl;
	std::cout<< "m = ";
	m.escribirMonomio();
	std::cout << std::endl << std::endl;

	// Asignación de un número a un polinomio
	std::cout<< "Asignación de un número a un polinomio --> p1 = x"<< std::endl;
	p1 = x;
	std::cout<< "p1 = ";
	p2.escribirPolinomio();
	std::cout << std::endl;
	std::cout<< "x = " << x;
	std::cout << std::endl << std::endl;

	std::cout << "Para continuar, pulse ";
	std::cout << INVERSE ;
	std::cout << "ENTER";
	std::cout << RESET;
	// Pausa
	std::cin.ignore();


	//////////////////////////////////////////////////////////
	std::cout<< "Escritura de los polinomios"<< std::endl << std::endl;
	std::cout<< "p1 = ";
	p1.escribirPolinomio();
	std::cout << std::endl << std::endl;

	std::cout<< "p2 = ";
	p2.escribirPolinomio();
	std::cout << std::endl << std::endl;

	std::cout<< "p3 = ";
	p3.escribirPolinomio();
	std::cout << std::endl << std::endl;

	std::cout << "Para continuar, pulse ";
	std::cout << INVERSE ;
	std::cout << "ENTER";
	std::cout << RESET;
	std::cout << std::endl << std::endl;

	std::cout << "número de monomios del polinomio p1: " << p1.getNumeroMonomios();
	std::cout << std::endl << std::endl;


	////////////////////////////////////////////////////////
	// Operadores aritméticos y asignación
	std::cout << BIGREEN;
	std::cout<< "Operadores artiméticos y asignación "<< std::endl;
	std::cout << RESET;

		// Entre dos polinomios
	std::cout << BIGREEN;
	std::cout<< "Operadores artiméticos y asignación: dos polinomios "<< std::endl;
	std::cout << RESET;

	// Operador de suma y asignación
	std::cout<< "Operador p1 += p2"<< std::endl;
	std::cout<< "p1 = ";
	p1.escribirPolinomio();
	std::cout << std::endl;
	std::cout<< "p2 = ";
	p2.escribirPolinomio();
	std::cout << std::endl;
	std::cout<< "Resultado p1 += p2"<< std::endl;
	p1 += p2;
	std::cout<< "p1 = ";
	p2.escribirPolinomio();
	std::cout << std::endl << std::endl;

	// Operador de resta y asignación
	std::cout<< "Operador p1 -= p2"<< std::endl;
	std::cout<< "p1 = ";
	p1.escribirPolinomio();
	std::cout << std::endl;
	std::cout<< "p2 = ";
	p2.escribirPolinomio();
	std::cout << std::endl;
	std::cout<< "Resultado p1 -= p2"<< std::endl;
	p1 -= p2;
	std::cout<< "p1 = ";
	p2.escribirPolinomio();
	std::cout << std::endl << std::endl;

	// Operador de multiplicación y asignación
	std::cout<< "Operador p1 *= p2"<< std::endl;
	std::cout<< "p1 = ";
	p1.escribirPolinomio();
	std::cout << std::endl;
	std::cout<< "p2 = ";
	p2.escribirPolinomio();
	std::cout << std::endl;
	std::cout<< "Resultado p1 *= p2"<< std::endl;
	p1 *= p2;
	std::cout<< "p1 = ";
	p2.escribirPolinomio();
	std::cout << std::endl << std::endl;

	// Operador de división y asignación
	std::cout<< "Operador p1 /= p2 "<< std::endl;
	if ((p2.getGrado() >= p1.getGrado()) and (not p2.esNulo()))
	{
		std::cout<< "p1 = ";
		p1.escribirPolinomio();
		std::cout << std::endl;
		std::cout<< "p2 = ";
		p2.escribirPolinomio();
		std::cout << std::endl;
		std::cout<< "Resultado p1 *= p2"<< std::endl;
		p1 /= p2;
		std::cout<< "p1 = ";
		p2.escribirPolinomio();
		std::cout << std::endl << std::endl;
	}
	else
	{
		std::cout << "No se puede dividir p1 entre p2, porque: " << std::endl;
		std::cout << "- el grado de p1 no es mayor o igual que el grado de p2" << std::endl;
		std::cout << "- o el polinomio p2 es nulo" << std::endl;
	}


	//
	std::cout << "Para continuar, pulse ";
	std::cout << INVERSE ;
	std::cout << "ENTER";
	std::cout << RESET;
	// Pausa
	std::cin.ignore();

	////////////////////////////////////////////////////////
	// Entre un polinomio y un monomio
	std::cout << BIGREEN;
	std::cout<< "Operadores artiméticos y asignación: polinomio y monomio "<< std::endl;
	std::cout << RESET;

	//
	// Operador de suma y asignación
	std::cout<< "Operador p3 += m"<< std::endl;
	p3 += m;
	std::cout<< "p3 = ";
	p3.escribirPolinomio();
	std::cout << std::endl;
	std::cout<< "m = ";
	m.escribirMonomio();
	std::cout << std::endl << std::endl;

	// Operador de resta y asignación
	std::cout<< "Operador p3 -= m "<< std::endl;
	p3 -= m;
	std::cout<< "p3 = ";
	p3.escribirPolinomio();
	std::cout << std::endl;
	std::cout<< "m = ";
	m.escribirMonomio();
	std::cout << std::endl << std::endl;

	// Operador de multiplicación y asignación
	std::cout<< "Operador p3 *= m "<< std::endl;
	p3 *= m;
	std::cout<< "p3 = ";
	p3.escribirPolinomio();
	std::cout << std::endl;
	std::cout<< "m = ";
	m.escribirMonomio();
	std::cout << std::endl << std::endl;

	// Operador de división y asignación
	std::cout<< "Operador p3 /= m "<< std::endl;
	if (p3.getGrado() >= m.getGrado())
	{
		p3 /= m;
	}
	else
	{
		std::cout << "No se puede dividir p3 entre m, porque el grado de p3 no es mayor o igual que el grado de m" << std::endl;
	}

	std::cout<< "p3 = ";
	p3.escribirPolinomio();
	std::cout << std::endl;
	std::cout<< "m = ";
	m.escribirMonomio();
	std::cout << std::endl << std::endl;

	//
	std::cout << "Para continuar, pulse ";
	std::cout << INVERSE ;
	std::cout << "ENTER";
	std::cout << RESET;
	// Pausa
	std::cin.ignore();

	////////////////////////////////////////////////////////
	// Entre un polinomio y un número
	std::cout << BIGREEN;
	std::cout<< "Operadores artiméticos y asignación: polinomio y número "<< std::endl;
	std::cout << RESET;

	//
	// Operador de suma y asignación
	std::cout<< "Operador p3 += x"<< std::endl;
	p3 += x;
	std::cout<< "p3 = ";
	p3.escribirPolinomio();
	std::cout << std::endl;
	std::cout<< "x = " << x << std::endl << std::endl;

	// Operador de resta y asignación
	std::cout<< "Operador p3 -= x"<< std::endl;
	p3 -= x;
	std::cout<< "p3 = ";
	p3.escribirPolinomio();
	std::cout << std::endl;
	std::cout<< "x = " << x << std::endl << std::endl;

	// Operador de multiplicación y asignación
	std::cout<< "Operador p3 *= x"<< std::endl;
	p3 *= x;
	std::cout<< "p3 = ";
	p3.escribirPolinomio();
	std::cout << std::endl;
	std::cout<< "x = " << x << std::endl << std::endl;

	// Operador de división y asignación
	std::cout<< "Operador p3 /= x "<< std::endl;
	if (std::abs(x) > COTA_ERROR)
	{
		p3 /= x;
	}
	else
	{
		std::cout << "No se puede dividir p3 entre x, porque x es 0.0" << std::endl;
	}

	std::cout<< "p3 = ";
	p3.escribirPolinomio();
	std::cout << std::endl;
	std::cout<< "x = " << x << std::endl << std::endl;

	//
	std::cout << "Para continuar, pulse ";
	std::cout << INVERSE ;
	std::cout << "ENTER";
	std::cout << RESET;
	// Pausa
	std::cin.ignore();
	std::cout << std::endl << std::endl;


	///////////////////////////////////////////////////////////////
	// Calcular el valor de un polinomo para un número real x
	std::cout << BIGREEN;
	std::cout<< "Valor de un polinomo para un número real x" << std::endl << std::endl;
	std::cout << RESET;

	std::cout<< "p1 = ";
	p1.escribirPolinomio();
	std::cout << std::endl;
	std::cout<< "p1(" << x << ") = " << p1.calcularValor(x) << std::endl << std::endl;

	std::cout<< "p2 = ";
	p1.escribirPolinomio();
	std::cout << std::endl;
	std::cout<< "p1(" << x << ") = " << p1.calcularValor(x) << std::endl << std::endl;

	std::cout<< "p3 = ";
	p3.escribirPolinomio();
	std::cout << std::endl;
	std::cout<< "p3(" << x << ") = " << p3.calcularValor(x) << std::endl << std::endl;
*/

	// Fin
	return;
}


///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////

void ed::operadoresExternosPolinomios()
{
  // QUITAR ESTAS SENTENCIAS Y EL COMENTARIO DE BLOQUE
  std::cout << BIGREEN;
  std::cout << "operadoresExternosPolinomios()" << std::endl;
  std::cout << RESET;
  std::cout << "Quitar el comentario de bloque cuando se haya codificado la clase Polinomio y los operadores externos de dicha clase" << std::endl << std::endl;

/*
	double x;

	// Constructor por defecto
	ed::Monomio m;

	// Constructor por defecto
	ed::Polinomio p1, p2;

	// Lectura y escritura de un número
	std::cout << BIGREEN;
	std::cout<< "Introduzca un número real" << std::endl;
	std::cout << RESET;
	std::cout<< "x --> ";
	std::cin >> x;

	// Lectura y escritura de un monomio usando los operadores de flujo
	std::cout << BIGREEN;
	std::cout<< "Lectura de un monomio usando los operadores de flujo" << std::endl;
	std::cout << RESET;
	std::cout<< "Coeficiente y grado del monomio (separados por espacios) " << std::endl;
	std::cout<< "m --> ";
	std::cin >> m;


	// Lectura y escritura usando los operadores de flujo
	std::cout << BIGREEN;
	std::cout<< "Lectura de polinomios usando los operadores de flujo" << std::endl;
	std::cout << RESET;
	std::cout<< "p1 --> ";
	std::cin >> p1;

	std::cout<< "p2 --> ";
	std::cin >> p2;

 	// Se elimina el salto de línea
	std::cin.ignore();


	/////////////////
	std::cout << BIGREEN;
	std::cout<< "Escritura de polinomios usando los operadores de flujo" << std::endl;
	std::cout << RESET;

	std::cout<< "p1 " << p1 << std::endl;
	std::cout<< "p2 = " << p2 << std::endl;

	//
	std::cout << "Para continuar, pulse ";
	std::cout << INVERSE ;
	std::cout << "ENTER";
	std::cout << RESET;
	// Pausa
	std::cin.ignore();


	// Operadores que no son miembros de la clase
	std::cout << BIGREEN;
	std::cout<< "Operadores que no son miembros de la clase" << std::endl << std::endl;
	std::cout << RESET;

	// Igualdad
	std::cout << BIYELLOW;
	std::cout<< "Operadores de igualdad" << std::endl << std::endl;
	std::cout << RESET;

	std::cout<< "Igualdad: p1 == p2" << std::endl;
    std::cout << "p1 = " << p1 ;
	if (p1 == p2)
		std::cout << " es igual que ";
	else
		std::cout << " no es igual que ";

    std::cout << "p2 = " << p2 << std::endl << std::endl;

	//
	std::cout<< "Igualdad: p1 == m" << std::endl;
    std::cout << "p1 = " << p1;
	if (p1 == m)
		std::cout << " es igual que ";
	else
		std::cout << " no es igual que ";

    std::cout << "m = " << m << std::endl << std::endl;


	//
	std::cout<< "Igualdad: m == p1" << std::endl;
    std::cout << "m = " << m;
	if (m == p1)
		std::cout << " es igual que ";
	else
		std::cout << " no es igual que ";

    std::cout << "p1 = " << p1 << std::endl << std::endl;


	//
	std::cout<< "Igualdad: p1 == x" << std::endl;
    std::cout << "p1 = " << p1 ;

	if (p1 == x)
		std::cout << " es igual que ";
	else
		std::cout << " no es igual que ";

    std::cout << x << std::endl << std::endl;

	//
	std::cout<< "Igualdad: x == p1" << std::endl;
    std::cout << x;

	if (x == p1)
		std::cout << " es igual que ";
	else
		std::cout << " no es igual que ";

	std::cout << "p1 = " << p1 << std::endl << std::endl;


	// Desigualdad
	std::cout << BIYELLOW;
	std::cout<< "Operadores de desigualdad" << std::endl << std::endl;
	std::cout << RESET;

	std::cout<< "Desigualdad: p1 != p2" << std::endl;
    std::cout << "p1 = " << p1 ;
	if (p1 != p2)
		std::cout << " no es igual que ";
	else
		std::cout << " es igual que ";

    std::cout << "p2 = " << p2 << std::endl << std::endl;


	//
	std::cout<< "Desigualdad: p1 != m" << std::endl;
    std::cout << "p1 = " << p1;
	if (p1 != m)
		std::cout << " no es igual que ";
	else
		std::cout << " es igual que ";

    std::cout << "m = " << m << std::endl << std::endl;


	//
	std::cout<< "Desigualdad: m != p1" << std::endl;
    std::cout << "m = " << m;
	if (m != p1)
		std::cout << " no es igual que ";
	else
		std::cout << " es igual que ";

    std::cout << "p1 = " << p1 << std::endl << std::endl;


	//
	std::cout<< "Desigualdad: p1 != x" << std::endl;
    std::cout << "p1 = " << p1 ;

	if (p1 != x)
		std::cout << " no es igual que ";
	else
		std::cout << " es igual que ";

    std::cout << x << std::endl << std::endl;

	//
	std::cout<< "Desigualdad: 3 != p1" << std::endl;
    std::cout << x;

	if (x != p1)
		std::cout << " no es igual que ";
	else
		std::cout << " es igual que ";

	std::cout << "p1 = " << p1 << std::endl << std::endl;

	//
	std::cout << "Para continuar, pulse ";
	std::cout << INVERSE ;
	std::cout << "ENTER";
	std::cout << RESET;
	// Pausa
	std::cin.ignore();


	////////////////

	// Unarios
	std::cout << BIYELLOW;
	std::cout<< "Operadores unarios" << std::endl << std::endl;
	std::cout << RESET;

	std::cout << "+ p1 = " << + p1 << std::endl;
	std::cout << "+ p2 = " << + p2 << std::endl;

	std::cout << "- p1 = " << - p1 << std::endl;
	std::cout << "- p2 = " << - p2 << std::endl;

	std::cout << std::endl;

	/////////////////////////////////////////
	// Operadores ariméticos binarios

	// Operaciones con dos polinomios
	std::cout << BIYELLOW;
	std::cout<< "Operadores ariméticos binarios con dos polinomios" << std::endl;
	std::cout << RESET;

	std::cout << "p1 + p2 = " << p1 + p2 << std::endl;
	std::cout << "p1 - p2 = " << p1 - p2 << std::endl;
	std::cout << "p1 * p2 = " << p1 * p2 << std::endl;

	if ( (p1.getGrado() >= p2.getGrado()) and (not p2.esNulo()) )
	{
		std::cout << "p1 / p2 = " << p1 / p2 << std::endl;
	}
	else
	{
		std::cout << BIRED;
		std::cout << "No se puede dividir p1 entre p2, porque: " << std::endl;
		std::cout << "- el grado de p1 no es mayor o igual que el grado de p2" << std::endl;
		std::cout << "- o el polinomio p2 es nulo" << std::endl;
		std::cout << RESET;
		std::cout << "p1 = " << p1 << std::endl;
		std::cout << "p2 = " << p2 << std::endl;
	}

	std::cout << std::endl;

	// Operaciones con un polinomio y un monomio
	std::cout << BIYELLOW;
	std::cout<< "Operadores ariméticos binarios con un polinomio y un monomio"
			 << std::endl;
	std::cout << RESET;

	std::cout << "p1 + m = " << p1 + m << std::endl;
	std::cout << "p1 - m = " << p1 - m << std::endl;
	std::cout << "p1 * m = " << p1 * m << std::endl;

	if (p1.getGrado() >= m.getGrado() and (std::abs(m.getCoeficiente()) > COTA_ERROR))
		std::cout << "p1 / m = " << p1 / m << std::endl;
	else
	{
		std::cout << BIRED;
		std::cout<< "No se puede realizar la  división del polinomio p1 por el monomio m porque" << std::endl;
		std::cout<< "- el grado de p1 no es mayor o igual que el grado de m" << std::endl;

		std::cout<< " - o el coeficiente del monomio m es 0.0" << std::endl;
		std::cout << RESET;
		std::cout << "p1 = " << p1 << std::endl;
		std::cout << "m = " << m << std::endl;
	}

	//
	std::cout << "m + p1 = " << m + p1 << std::endl;
	std::cout << "m - p1 = " << m - p1 << std::endl;
	std::cout << "m * p1 = " << m * p1 << std::endl;

	if ( (m.getGrado() >= p1.getGrado())  and (not p1.esNulo()))
		std::cout << "m / p1 = " << m / p1 << std::endl;
	else
	{
		std::cout << BIRED;
		std::cout<< "No se puede realizar la  división del monomio m por p1 porque " << std::endl;
		std::cout << "- el grado de m no es mayor o igual que el grado de p1" << std::endl;
		std::cout << "- o el polinomio p1 es nulo" << std::endl;

		std::cout << RESET;
		std::cout << "p1 = " << p1 << std::endl;
		std::cout << "m = " << m << std::endl;
	}

	std::cout << std::endl;

	// Operaciones con un polinomio y un número
	std::cout << BIYELLOW;
	std::cout<< "Operaciones con un polinomio y un número" << std::endl;
	std::cout << RESET;
	std::cout << "p1 = " << p1 << std::endl;

	std::cout << "p1 + x = " << p1 + x << std::endl;
	std::cout << "p1 - x = " << p1 - x << std::endl;
	std::cout << "p1 * x = " << p1 * x << std::endl;
	std::cout << "p1 / x = " << p1 / x << std::endl;

	if (std::abs(x) < COTA_ERROR)
	{
		std::cout << "p1 / x = " << p1 / x << std::endl;
	}
	else
	{
		std::cout << BIRED;
		std::cout<< "No se puede realizar la  división porque x es igual 0.0" << std::endl;
		std::cout << RESET;
		std::cout << "p1 = " << p1 << std::endl;
		std::cout << "x = " << x << std::endl;
	}

	//
	std::cout << "x + p1 = " << x + p1 << std::endl;
	std::cout << "x - p1 = " << x - p1 << std::endl;
	std::cout << "x * p1 = " << x * p1 << std::endl;

	if (      (p1.getGrado() == 0)
          and (std::abs(p1.getMonomio(p1.getGrado()).getCoeficiente())> 0.0)
		)
	{
		std::cout << "x / p1 = " << x / p1 << std::endl;
	}
	else
	{
		std::cout << BIRED;
		std::cout<< "No se puede realizar la  división de x por p1 " << std::endl;
		std::cout<< "- el polinomio p1 no tiene grado 0" << std::endl;
		std::cout<< "- o el polinomio p1 es el número 0.0" << std::endl;

		std::cout << RESET;
		std::cout << "p1 = " << p1 << std::endl;
		std::cout << "x = " << x << std::endl;
	}

	//


	std::cout << std::endl;
*/
	return;
}
