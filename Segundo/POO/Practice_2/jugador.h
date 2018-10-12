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

class Jugador : public Persona{
  private:
    int money_;
    string id_;
    list <int> bets_;
  public:
    Jugador(const string &dni, const string &id, const string &name = "", const
    string &surnames = "", const int age = 0, const string &address = "", const
    string &locality = "", const string &province = "", const string &country = "");
    string getCodigo() const {return id_;}
    int getDinero() const {return money_;}
    list getApuestas() const {return bets_;}
    void setCodigo(string &id) {id_ = id;}
    void setDinero(int money) {money_ = money;}
    void setApuestas();
};

#endif
