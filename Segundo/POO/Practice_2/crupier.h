#ifndef CRUPIER_H
#define CRUPIER_H

#include <string>
using std::string;

class Crupier : public Persona {
  private:
    string id_;
  public:
    Crupier (string dni, string id, string name = "", string surnames = "",
    int edad = 0, string address = "", string locality = "",
    string province = "", string country = "") : Persona (dni, name, surnames,
    age, address, locality, province) {id_ = id;}
  };

#endif
