#include <string>
#include "persona.h"
using std::string;

Persona::Persona (string dni, string name, string surnames, int age,
string address, string locality, string province, string country) {
  dni_ = dni;
  name_ = name;
  surnames_ = surnames;
  age_ = age;
  address_ = address;
  locality_ = locality;
  province_ = province;
  country_ = country;
}

string Persona::getApellidosyNombre() const {
  string full_name;
  full_name = surnames_ + ", " + name_;
  return full_name;
}

bool Persona::setEdad(int age) {
  if (age < 0 || age > 140) return false;
  else {
    age_ = age;
    return true;
  }
}

bool Persona::mayor() const {
  if (age_ >= 18) return true;
  else return false;
}
