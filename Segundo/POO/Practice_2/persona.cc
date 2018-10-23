/*----------------------------------------------------------------------------------
Practice 2 Class Persona
persona.cc
This is the file where are the implementation of some methods (the ones that are
not inline) from the class 'Persona'
----------------------------------------------------------------------------------*/

#include "persona.h"

Persona::Persona (const string &dni, const string &name, const string &surnames,
const int age, const string &address, const string &locality,
const string &province, const string &country) {
  setDNI(dni);
  setNombre(name);
  setApellidos(surnames);
  setEdad(age);
  setDireccion(address);
  setLocalidad(locality);
  setProvincia(province);
  setPais(country);
}

bool Persona::setEdad(int age) {
  if (age < 0 || age > 140) return false;
  else {
    age_ = age;
    return true;
  }
}

bool Persona::mayor() const {
  if (getEdad() >= 18) return true;
  else return false;
}
