/*----------------------------------------------------------------------------------
Practice 2 Class Persona
persona.h
This is the header file for the class 'Persona' which is going to have some inherited
classes (Crupier, Jugador)
----------------------------------------------------------------------------------*/

#ifndef PERSONA_H
#define PERSONA_H

#include <string>
using std::string;


class Persona {
  private:
    string dni_;
    string name_;
    string surnames_;
    int age_;
    string address_;
    string locality_;
    string province_;
    string country_;
  public:
    //Constructor
    Persona (const string &dni, const string &name = "", const string &surnames = "",
    const int age = 0, const string &address = "", const string &locality = "",
    const string &province = "", const string &country = "");
    //Getter methods
    string getDNI() const {return dni_;}
    string getNombre() const {return name_;}
    string getApellidos() const {return surnames_;}
    int getEdad() const {return age_;}
    string getDireccion() const {return address_ ;}
    string getLocalidad() const {return locality_;}
    string getProvincia() const {return province_;}
    string getPais() const {return country_;}
    //concatenates name and surnames with format "surnames, name"
    string getApellidosyNombre() const;
    //Setter methods
    void setDNI(string &dni) {dni_ = dni;}
    void setNombre(string &name) {name_ = name;}
    void setApellidos(string &surnames) {surnames_ = surnames;}
    bool setEdad(int age);
    void setDireccion(string &address) {address_ = address;}
    void setLocalidad(string &locality) {locality_ = locality;}
    void setProvincia(string &province) {province_ = province;}
    void setPais(string &country) {country_ = country;}
    //Other methods
    bool mayor() const;
};

#endif
