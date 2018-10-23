/*----------------------------------------------------------------------------------
Practice 2 Class Crupier
crupier.h
This is the file where is implemented the constructor of the class Crupier. The
constructor calls to the one of Persona class to get the parameters
----------------------------------------------------------------------------------*/

#include "crupier.h"

Crupier::Crupier(const string &dni, const string &id, const string &name,
const string &surnames, const int age, const string &address,
const string &locality, const string &province, const string &country)
: Persona (dni, name, surnames, age, address, locality, province, country) {
  id_ = id;
}
