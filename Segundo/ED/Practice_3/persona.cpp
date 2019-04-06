#include <iostream>
#include <cstring>
#include "persona.hpp"

///////////////////////////////////////////////////////////////
// --------------------------------------------- Constructores
//////////////////////////////////////////////////////////////

Persona::Persona(const char * n, const char * a, const int &d)
{
	nombre(n);
	apellido(a);
	dni(d);
	borrado('n');
};

Persona::Persona()
{
	nombre("");
	apellido("");
	dni(0);
	borrado('n');
};

Persona::Persona(const Persona &p)
{
	*this = p;
};

///////////////////////////////////////////////////////////////
// ---------------------------------- Operadores sobrecargados
//////////////////////////////////////////////////////////////

Persona & Persona::operator=(const Persona &p)
{
	if (this != &p)
	{
		nombre(p.nombre());
		apellido(p.apellido());
		dni(p.dni());
	}
	return *this;
};

bool Persona::operator==(const Persona &p) const
{
	return dni() == p.dni();
};

bool Persona::operator!=(const Persona &p) const
{
	return dni() != p.dni();
};

bool Persona::operator<(const Persona &p) const
{
	return dni() < p.dni();
};

bool Persona::operator>(const Persona &p) const
{
	return dni() > p.dni();
};

ostream & operator<<(ostream &stream, const Persona &p)
{
	stream << p.nombre() << " " << p.apellido() << " " << p.dni() << endl;
	return stream;
};

istream &operator>>(istream &stream, Persona &p)
{
	char aux[30];
	int dni;
	cout << "Nombre: ";
	stream >> aux;
	p.nombre(aux);
	cout << "Apellido: ";
	stream >> aux;
	p.apellido(aux);
	cout << "Dni: ";
	stream >> dni;
	p.dni(dni);

	return stream;
};

///////////////////////////////////////////////////////////////
// ----------------------------------------- Getters y Setters
//////////////////////////////////////////////////////////////

char *Persona::nombre()const
{
	return (char *)_nombre;
};

char * Persona::apellido()const
{
	return (char *)_apellido;
};

const int &Persona::dni() const
{
	return _dni;
};

const char &Persona::borrado() const
{
	return _borrado;
};

void Persona::nombre(const char * nombre)
{
	strcpy(_nombre, nombre);
};

void Persona::apellido(const char * apellido)
{
	strcpy(_apellido, apellido);
};

void Persona::dni(const int &dni)
{
	_dni = dni;
};

void Persona::borrado(const char &borrado)
{
	_borrado = borrado;
};

///////////////////////////////////////////////////////////////
// --------------------------------------------------- Metodos
//////////////////////////////////////////////////////////////

void Persona::mostrarPersona() const
{
	cout << "Nombre: " << nombre() << " Apellido: " << apellido() << " Dni: " << dni() << endl;
}
