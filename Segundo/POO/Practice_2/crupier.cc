#include <iostream>
#include <string>
#include "crupier.h"
using std::string;

Crupier::Crupier (const string &dni, const string &id, const string &name, string surnames, int age,
string address, string locality,string province, string country) : Persona (dni,
name, surnames, age, address, locality, province) {
  id_ = id;
}

int main() {
  Crupier c("3332", "44X");
  std::cout << "DNI = " << c.getDNI() << '\n';
  std::cout << "Codigo = " << c.getCodigo() << '\n';
  return 0;
}
