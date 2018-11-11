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
    string identifier_; //alphanumeric code to identify the crupier
  public:
    //Constructor
    //'DNI' and 'identifier' are necessary for the declaration of a 'Crupier' object
    Crupier(const string &dni, const string &identifier, const string &name = "",
    const string &surnames = "", const int age = 0, const string &address = "",
    const string &locality = "", const string &province = "", const string &country = "");
    //Getters
    string getCodigo() const {return identifier_;}
    //Setters
    void setCodigo(const string &identifier) {identifier_ = identifier;}
};

#endif
