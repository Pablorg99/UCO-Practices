#include "crupier.h"
#include <string>
using std::string;

Crupier::Crupier (string dni, string id, string name, string surnames,
int age, string address, string locality, string province,string country) :
Persona (dni, name, surnames, age, address, locality, province) {id_ = id;}
