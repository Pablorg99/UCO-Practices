/*----------------------------------------------------------------------------------
Practice 2 Class Crupier
crupier.h
This is the header file for the class Crupier that is inherited from the class
Persona
----------------------------------------------------------------------------------*/

#ifndef CRUPIER_H
#define CRUPIER_H

#include "persona.h"

class Crupier : public Persona {
  private:
    string id_;
  public:
    Crupier(const string &dni, const string &id, const string &name = "",
    const string &surnames = "", const int age = 0, const string &address = "",
    const string &locality = "", const string &province = "", const string &country = "");
    string getCodigo() const {return id_;}
    void setCodigo(string &id) {id_ = id;}
};

#endif
