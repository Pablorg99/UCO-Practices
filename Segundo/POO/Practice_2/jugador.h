/*------------------------------------------------------------------------------
Practice 2 Class Jugador
jugador.h
Header file for class 'Jugador', inherited from class 'Persona'
------------------------------------------------------------------------------*/
#ifndef JUGADOR_H
#define JUGADOR_H

#include "persona.h"
#include <list>
using std::list;

class Apuesta {
  public:
    int tipo;
    string valor;
    int cantidad;
};

class Jugador : public Persona{
  private:
    int money_;
    string identifier_;
    list <Apuesta> bets_;
  public:
    //Constructor
    //'DNI' and 'identifier' are necessary for the declaration of a 'Crupier' object
    Jugador(const string &dni, const string &id, const string &name = "", const
    string &surnames = "", const int age = 0, const string &address = "", const
    string &locality = "", const string &province = "", const string &country = "");
    //Getter methods
    string getCodigo() const {return identifier_;}
    int getDinero() const {return money_;}
    list <Apuesta> getApuestas() const {return bets_;}
    //Setter methods
    void setCodigo(const string &id) {identifier_ = id;}
    void setDinero(const int money) {money_ = money;}
    void setApuestas();
};

#endif
