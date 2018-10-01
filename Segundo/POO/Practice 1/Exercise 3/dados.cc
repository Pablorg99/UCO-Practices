/*------------------------------------------------------------------------------
Practice 1 Exercise 3
dados.cc
In this file is the method's body from the class 'Dados'
------------------------------------------------------------------------------*/
#include <cstdlib>  //necessary to use 'rand()' and 'srand()'
#include <ctime>    //necessary to use 'time()'
#include "dados.h"

Dados::Dados () {
  srand(time(NULL));
  d1_ = 1;
  d2_ = 1;
}

bool Dados::setDado1 (int n) {
  if (n < 1 || n > 6) return false;
  else {
    d1_ = n;
    return true;
  }
}

bool Dados::setDado2 (int n) {
  if (n < 1 || n > 6) return false;
  else {
    d2_ = n;
    return true;
  }
}

void Dados::lanzamiento () {
  d1_ = (rand() % 6) + 1;
  d2_ = (rand() % 6) + 1;
}
