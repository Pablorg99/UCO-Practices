/*------------------------------------------------------------------------------
Practice 2 Class Jugador
jugador.cc
File for the implementation of some methods from the class 'Jugador', inherited
from the class 'Persona'
------------------------------------------------------------------------------*/

#include "jugador.h"
#include <fstream>
using std::ifstream;

//Base initializers with parameters from class 'Persona'
Jugador::Jugador(const string &dni, const string &identifier, const string &name, const
string &surnames, const int age, const string &address, const string &locality, const string
&province, const string &country) : Persona (dni, name, surnames, age, address,
locality, province, country) {
  setCodigo(identifier);
  setDinero(1000);
}

void Jugador::setApuestas () {
  //Remove all data on bets_ list
  bets_.clear();
  //Auxiliar variables to store struct parameters and values between commas
  Apuesta bet;
  string value;
  //Open the file "DNI.txt" where DNI is the 'dni' of the object
  ifstream file(getDNI() + ".txt");  
  //file.eof() do an extra read when all lines are read
  //getline returns false when there is not any line to read
  while(getline(file, value, ',')) {
    bet.tipo = stoi(value);
    getline(file, value, ',');
    bet.valor = value;
    getline(file, value, '\n');
    bet.cantidad = stoi(value);
    //save in the list the values of bet
    bets_.push_back(bet);
  }
  file.close();
}