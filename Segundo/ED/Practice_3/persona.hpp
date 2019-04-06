#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>
using namespace std;

class Persona
{
private:
	char _nombre[30];
	char _apellido[30];
	int _dni;
	char _borrado;

public:
	// constructores de la clase Persona
	Persona();
	Persona(const char * n, const char * a, const int &d);
	Persona(const Persona &p);

	// operadores sobrecargados
	Persona & operator=(const Persona &p);
	bool operator==(const Persona &p)const;
	bool operator!=(const Persona &p)const;
	bool operator<(const Persona &p) const;
	bool operator>(const Persona &p) const;
	friend ostream & operator<<(ostream &stream, const Persona &p);
	friend istream & operator>>(istream &stream, Persona &p);

	// getters y setters de la clase Persona
	char * nombre()const;
	char * apellido()const;
	const int &dni()const;
	const char &borrado() const;
	void nombre(const char * nombre);
	void apellido(const char * apellido);
	void dni(const int &dni);
	void borrado(const char &borrado);

	// metodos de la clase Persona
	void mostrarPersona() const;
};

#endif
