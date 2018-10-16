/*------------------------------------------------------------------------------
Practice 2 Class Jugador
jugador.cc
File for the implementation of some methods from the class 'Jugador', inherited
from the class 'Persona'
------------------------------------------------------------------------------*/

#include "jugador.h"

Jugador::Jugador(const string &dni, const string &id, const string &name, const
string &surnames, const int, const string, conststring &locality, const string
&province, const string &country) : Persona (dni, name, surnames, age, address,
locality, province, country) {
  id_ = id;
  money_ = 1000;
}

void setApuestas () {
  
}
