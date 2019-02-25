//FILE PROVIDED BY UNIVERSITY

/*!
  \file   funcionesAuxiliares.cpp
  \brief  Código de las funciones auxiliares para el programa principal de la práctica 1
  \author 
  \date   
*/

// Para los flujos de entrada y salida
#include <iostream>
#include <string>

#include "macros.hpp"
#include "funcionesAuxiliares.hpp"

#include "Monomio.hpp"
#include "operadoresExternosMonomios.hpp"

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
	std::cout << "[1] Test de la clase Monomio" << std::endl;

	PLACE(posicion++,10);
	std::cout << "[2] Operadores externos de la clase Monomio " << std::endl;

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
void ed::testMonomio()
{
	// QUITAR ESTAS SENTENCIAS Y EL COMENTARIO DE BLOQUE
	std::cout << BIGREEN;
	std::cout << "testMonomio()" << std::endl;
	std::cout << RESET;
	std::cout << "Quitar el comentario de bloque cuando se haya codificado la clase Monomio " << std::endl << std::endl;


	double x;

	// Constructor sin argumentos
	ed::Monomio m1;

	// Constructor parametrizado
	ed::Monomio m2(1,2);

	// Constructor de copia
	ed::Monomio m3(m2);

	// Lectura y escritura de un número
	std::cout << BIGREEN;
	std::cout<< "Introduzca un número real" << std::endl;
	std::cout << RESET;
	std::cout<< "x --> ";
	std::cin >> x;

	// Lectura y escritura usando funciones de la clase Monomio
	std::cout << BIGREEN;
	std::cout<< "Lectura y escritura"<< std::endl << std::endl;
	std::cout << RESET;
	m1.leerMonomio();
	std::cout << std::endl;

	std::cout<< "Escritura de los monomios"<< std::endl << std::endl;
	std::cout<< "m1 = ";
	m1.escribirMonomio();
	std::cout << std::endl << std::endl;

	std::cout<< "m2 = ";
	m2.escribirMonomio();
	std::cout << std::endl << std::endl;

	std::cout<< "m3 = ";
	m3.escribirMonomio();
	std::cout << std::endl << std::endl;

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

	std::cout<< "Operador de asignación de un monomio a otro monomio --> m2 = m1 "<< std::endl;
	m2 = m1;
	std::cout<< "m1 = ";
	m1.escribirMonomio();
	std::cout << std::endl;
	std::cout<< "m2 = ";
	m2.escribirMonomio();
	std::cout << std::endl << std::endl;

	// Asignación de un número a un monomio
	std::cout<< "Asignación de un número a un monomio --> m3 = " << x << std::endl;
	m3 = x;
	std::cout<< "m3 = ";
	m3.escribirMonomio();
	std::cout << std::endl;
	std::cout<< "x = " << x; 
	std::cout << std::endl << std::endl;

	std::cout << "Para continuar, pulse ";
	std::cout << INVERSE ;
	std::cout << "ENTER";
	std::cout << RESET;
	// Pausa
	std::cin.ignore();

	////////////////////////////////////////////////////////
	// Operadores aritméticos y asignación
	std::cout << BIGREEN;
	std::cout<< "Operadores artiméticos y asignación "<< std::endl;
	std::cout << RESET;	

	std::cout << BIYELLOW;
	std::cout<< "Operadores artiméticos y asignación con dos monomios"<< std::endl;
	std::cout << RESET;	


	// Operador de suma y asignación 
	std::cout<< "Operador m1 += m2"<< std::endl;
	std::cout<< "m1 = ";
	m1.escribirMonomio();
	std::cout << std::endl;
	std::cout<< "m2 = ";
	m2.escribirMonomio();
	std::cout << std::endl;
	std::cout<< "Resultado de m1 += m2"<< std::endl;
	m1 += m2;
	std::cout<< "m1 = ";
	m1.escribirMonomio();
	std::cout << std::endl << std::endl;

	// Operador de resta y asignación 
	std::cout<< "Operador m1 -= m2"<< std::endl;
	std::cout<< "m1 = ";
	m1.escribirMonomio();
	std::cout << std::endl;
	std::cout<< "m2 = ";
	m2.escribirMonomio();
	std::cout << std::endl;
	std::cout<< "Resultado de m1 -= m2"<< std::endl;
	m1 -= m2;
	std::cout<< "m1 = ";
	m1.escribirMonomio();
	std::cout << std::endl << std::endl;

	// Operador de multiplicación y asignación 
	std::cout<< "Operador m1 *= m2"<< std::endl;
	std::cout<< "m1 = ";
	m1.escribirMonomio();
	std::cout << std::endl;
	std::cout<< "m2 = ";
	m2.escribirMonomio();
	std::cout << std::endl;
	std::cout<< "Resultado de m1 *= m2"<< std::endl;
	m1 *= m2;
	std::cout<< "m1 = ";
	m1.escribirMonomio();
	std::cout << std::endl << std::endl;

	// Operador de división y asignación 
	if ((m1.getGrado() >= m2.getGrado()) and (std::abs(m2.getCoeficiente() )> COTA_ERROR))
	{
		std::cout<< "Operador m1 /= m2"<< std::endl;
		std::cout<< "m1 = ";
		m1.escribirMonomio();
		std::cout << std::endl;
		std::cout<< "m2 = ";
		m2.escribirMonomio();
		std::cout << std::endl;
		std::cout<< "Resultado de m1 /= m2"<< std::endl;
		m1 /= m2;
		std::cout<< "m1 = ";
		m1.escribirMonomio();
		std::cout << std::endl << std::endl;
	}
	else
	{
		std::cout << BIRED;
		std::cout<< "No se puede realizar la  división del monomio m1 por el monomio m2 porque: " << std::endl;
		std::cout<< "- el grado del monomio m1 no es mayor o igual que el grado del monomio m2" << std::endl;
		std::cout<< "- o el coeficiente del monomio m2 es 0.0" << std::endl;
		std::cout << RESET;
		std::cout<< "m1 = ";
		m1.escribirMonomio();
		std::cout << std::endl;
		std::cout<< "m2 = ";
		m2.escribirMonomio();
		std::cout << std::endl;
	}

	// 
	std::cout << "Para continuar, pulse ";
	std::cout << INVERSE ;
	std::cout << "ENTER";
	std::cout << RESET;
	// Pausa
	std::cin.ignore();


	///////////////////////////////////////////

	std::cout << BIYELLOW;
	std::cout<< "Operadores artiméticos y asignación con un monomio y un número "<< std::endl;
	std::cout << RESET;	

	// Operador de multiplicación por un número y asignación 
	std::cout<< "Operador m1 *= x "<< std::endl;
	std::cout<< "m1 = ";
	m1.escribirMonomio();
	std::cout << std::endl;
	std::cout<< "x = " << x; 
	std::cout << std::endl;
	std::cout<< "Resultado de m1 *= x "<< std::endl;
	m1 *= x;
	std::cout<< "m1 = ";
	m1.escribirMonomio();
	std::cout << std::endl << std::endl;

	// Operador de división por un número y asignación 
	if (std::abs(x) > COTA_ERROR)
	{
		std::cout<< "Operador m1 /= x "<< std::endl;
		std::cout<< "m1 = ";
		m1.escribirMonomio();
		std::cout << std::endl;
		std::cout<< "x = " << x; 
		std::cout << std::endl;
		std::cout<< "Resultado de m1 /= x "<< std::endl;
		m1 /= x;
		std::cout<< "m1 = ";
		m1.escribirMonomio();
		std::cout << std::endl << std::endl;
	}
	else
	{
		std::cout << BIRED;
		std::cout<< "No se puede realizar la  división del monomio m1 por el número x: " << std::endl;
		std::cout<< "el número x es igual a 0.0" << std::endl;
		std::cout << RESET;
		std::cout << std::endl;
	}

	// 
	std::cout << "Para continuar, pulse ";
	std::cout << INVERSE ;
	std::cout << "ENTER";
	std::cout << RESET;
	// Pausa
	std::cin.ignore();

	///////////////////////////////////////////////////////////////
	// Calcular el valor de un monomio para un número real x
	std::cout << BIGREEN;
	std::cout<< "Valor de un monomio para un número real " << x << std::endl << std::endl;
	std::cout << RESET;

	std::cout<< "m1 = ";
	m1.escribirMonomio();	
	std::cout << std::endl;
	std::cout<< "m1(" << x << ") = " << m1.calcularValor(x) << std::endl << std::endl;

	std::cout<< "m2 = ";
	m1.escribirMonomio();
	std::cout << std::endl;
	std::cout<< "m2(" << x << ") = " << m2.calcularValor(x) << std::endl << std::endl;

	std::cout<< "m3 = ";
	m3.escribirMonomio();
	std::cout << std::endl;
	std::cout<< "m3(" << x << ") = " << m3.calcularValor(x) << std::endl << std::endl;


	// Fin
	return;
}


///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////

void ed::operadoresExternosMonomios()
{
	// QUITAR ESTAS SENTENCIAS Y EL COMENTARIO DE BLOQUE
	std::cout << BIGREEN;
	std::cout << "operadoresExternosMonomios()" << std::endl;
	std::cout << RESET;
	std::cout << "Quitar el comentario de bloque cuando se haya codificado la clase Monomio y los operadores externos de dicha clase" << std::endl << std::endl;


	double x;

	// Constructor por defecto
	ed::Monomio m1, m2, m3;

	// Lectura y escritura de un número
	std::cout << BIGREEN;
	std::cout<< "Introduzca un número real" << std::endl;
	std::cout << RESET;
	std::cout<< "x --> ";
	std::cin >> x;


	// Lectura y escritura usando los operadores de flujo
	std::cout << BIGREEN;
	std::cout<< "Lectura de monomios usando los operadores de flujo" << std::endl;
	std::cout << RESET;
	std::cout<< "Coeficiente y grado del monomio (separados por espacios) " << std::endl;

	std::cout<< "m1 --> ";
	std::cin >> m1;

	std::cout<< "m2 --> ";
	std::cin >> m2;

	std::cout<< "m3 --> ";
	std::cin >> m3;
 	// Se elimina el salto de línea
	std::cin.ignore();


	/////////////////
	std::cout << BIGREEN;
	std::cout<< "Escritura de monomios usando los operadores de flujo" << std::endl;
	std::cout << RESET;
	
	std::cout<< "m1 = " << m1 << std::endl;
	std::cout<< "m2 = " << m2 << std::endl;
	std::cout<< "m3 = " << m3 << std::endl;

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

	std::cout<< "Igualdad: m1 == m2" << std::endl;
    std::cout << "m1 = " << m1 ;	
	if (m1 == m2)
		std::cout << " es igual que ";
	else
		std::cout << " no es igual que ";

    std::cout << "m2 = " << m2 << std::endl << std::endl;


	// 
	std::cout<< "Igualdad: m1 == " << x << std::endl;
    std::cout << "m1 = " << m1 ;	

	if (m1 == x)
		std::cout << " es igual que ";
	else
		std::cout << " no es igual que ";

    std::cout << x << std::endl << std::endl;

	//
	std::cout<< "Igualdad: " << x << " == m1" << std::endl;
    std::cout << x;

	if (x == m1)
		std::cout << " es igual que ";
	else
		std::cout << " no es igual que ";
	
	std::cout << "m1 = " << m1 << std::endl << std::endl;


	// Desigualdad
	std::cout << BIYELLOW;
	std::cout<< "Operadores de desigualdad" << std::endl << std::endl;
	std::cout << RESET;

	std::cout<< "Desigualdad: m1 != m2" << std::endl;
    std::cout << "m1 = " << m1 ;	
	if (m1 != m2)
		std::cout << " no es igual que ";
	else
		std::cout << " es igual que ";

    std::cout << "m2 = " << m2 << std::endl << std::endl;


	// 
	std::cout<< "Desigualdad: m1 != " << x << std::endl;
    std::cout << "m1 = " << m1 ;	

	if (m1 != x)
		std::cout << " no es igual que ";
	else
		std::cout << " es igual que ";

    std::cout << x << std::endl << std::endl;

	//
	std::cout<< "Desigualdad: " << x << " != m1" << std::endl;
    std::cout << x;    

	if (x != m1)
		std::cout << " no es igual que ";
	else
		std::cout << " es igual que ";
	
	std::cout << "m1 = " << m1 << std::endl << std::endl;

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

	std::cout << "+ m1 = " << + m1 << std::endl;
	std::cout << "- m1 = " << - m1 << std::endl;		

	std::cout << "+ m2 = " << + m2 << std::endl;
	std::cout << "- m2 = " << - m2 << std::endl;

	std::cout << std::endl;

	// Operadores ariméticos binarios
	std::cout << BIYELLOW;
	std::cout<< "Operadores ariméticos binarios" << std::endl;
	std::cout << RESET;

	if (m1.getGrado() == m2.getGrado())
	{
		std::cout << "m1 + m2 = " << m1 + m2 << std::endl;
		std::cout << "m1 - m2 = " << m1 - m2 << std::endl;
	}
	else
	{
		std::cout << BIRED;
		std::cout<< "No se puede realizar la suma ni la resta de m1 y m2 porque no tienen el mismo grado" << std::endl;
		std::cout << RESET;
		std::cout << "m1 = " << m1 << std::endl;
		std::cout << "m2 = " << m2 << std::endl;
	}

	std::cout << "m1 * m2 = " << m1 * m2 << std::endl;


	if ((m1.getGrado() >= m2.getGrado()) and (std::abs(m2.getCoeficiente() )> COTA_ERROR))
	{
		std::cout << "m1 / m2 = " << m1 / m2 << std::endl;
	}
	else
	{
		std::cout << BIRED;
		std::cout<< "No se puede realizar la  división del monomio m1 por el monomio m2 porque: " << std::endl;
		std::cout<< "- el grado del monomio m1 no es mayor o igual que el grado del monomio m2" << std::endl;
		std::cout<< "- o el coeficiente del monomio m2 es 0.0" << std::endl;
		std::cout << RESET;
		std::cout<< "m1 = ";
		m1.escribirMonomio();
		std::cout << std::endl;
		std::cout<< "m2 = ";
		m2.escribirMonomio();
		std::cout << std::endl;
	}

	std::cout << std::endl;

	// Operaciones con números y monomios
	std::cout << BIYELLOW;
	std::cout<< "Multiplicación y división con un monomio y un número" << std::endl;
	std::cout << RESET;

	std::cout << "m1 = " << m1 << std::endl;
	std::cout << "m1 * " << x << " = " << m1 * x << std::endl;
	std::cout << x << " * m1 = " << x * m1 << std::endl;

	if (std::abs(x) > COTA_ERROR)
	{
		std::cout << "m1 / " << x << " = " << m1 / x << std::endl;
	}
	else
	{
	std::cout << BIRED;
		std::cout<< "No se puede realizar la  división de un monomio por un número igual a 0.0 " << std::endl;
		std::cout << RESET;
	}

	if ((m1.getGrado() != 0) or (std::abs(m1.getCoeficiente()) < COTA_ERROR))
	{		
		std::cout << BIRED;
		std::cout<< "No se puede realizar la  división de un número por el monomio m1 porque su grado no es 0 o su coeficiente es 0.0" << std::endl;
		std::cout << RESET;
		std::cout << "m1 = " << m1 << std::endl;
	}
	else
	{
	std::cout << x << " / m1 = " << x / m1 << std::endl;
	}


	std::cout << std::endl;

	return;
}
