/*------------------------------------------------------------------------------
Practice 2 Class Jugador
jugador.h
Header file for class 'Jugador', inherited from class 'Persona'
------------------------------------------------------------------------------*/
#ifndef JUGADOR_H
#define JUGADOR_H

#include "persona.h"
#include <list>
#include <string>
using std::string;

class Apuesta {
  public:
    int type;
    string value;
    int money;
};

class Jugador : public Persona{
  private:
    int money_;
    string id_;
    list <Apuesta> bets_;
  public:
    //Constructor
    Jugador(const string &dni, const string &id, const string &name = "", const
    string &surnames = "", const int age = 0, const string &address = "", const
    string &locality = "", const string &province = "", const string &country = "");
    string getCodigo() const {return id_;}
    //Getter methods
    int getDinero() const {return money_;}
    list <Apuesta> getApuestas() const {return bets_;}
    //Setter methods-
    void setCodigo(const string &id) {id_ = id;}
    void setDinero(int money) {money_ = money;}
    void setApuestas();
};

#endif
