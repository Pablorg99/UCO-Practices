/*------------------------------------------------------------------------------
Practice 2 Class Jugador
jugador.cc
File for the implementation of some methods from the class 'Jugador', inherited
from the class 'Persona'
------------------------------------------------------------------------------*/

#include "jugador.h"
#include <fstream>
using std::ifstream;

Jugador::Jugador(const string &dni, const string &id, const string &name, const
string &surnames, const int age, const string &address, const string &locality, const string
&province, const string &country) : Persona (dni, name, surnames, age, address,
locality, province, country) {
  setCodigo(id);
  setDinero(1000);
}

void Jugador::setApuestas () {
  bets_.clear();
  Apuesta bet;
  string value;
  ifstream file(getDNI() + ".txt");  
  //file.eof() do an extra read when all lines are read
  //getline returns false when there is not any line to read
  while(getline(file, value, ',')) {
    bet.tipo = stoi(value);
    getline(file, value, ',');
    bet.valor = value;
    getline(file, value);
    bet.cantidad = stoi(value);

    bets_.push_back(bet);
  }  
}