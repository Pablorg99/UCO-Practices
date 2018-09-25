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
  throws_d1_ = 0;
  throws_d2_ = 0;
  addition_d1_ = 0;
  addition_d2_ = 0;
}

int Dados::getDado1 () {
  return d1_;
}

int Dados::getDado2 () {
  return d2_;
}

bool Dados::setDado1 (int n) {
  if (n < 1 || n > 6) return false;
  else {
    d1_ = n;
    throws_d1_++;
    addition_d1_ += d1_;
    return true;
  }
}

bool Dados::setDado2 (int n) {
  if (n < 1 || n > 6) return false;
  else {
    d2_ = n;
    throws_d2_++;
    addition_d2_ += d2_;
    return true;
  }
}

void Dados::lanzamiento () {
  d1_ = (rand() % 6) + 1;
  d2_ = (rand() % 6) + 1;
  throws_d1_++;
  throws_d2_++;
  addition_d1_ += d1_;
  addition_d2_ += d2_;
}

int Dados::getSuma () {
  int suma;
  suma = d1_ + d2_;
  return suma;
}

int Dados::getDiferencia () {
  int diferencia;
  diferencia = d1_ - d2_;
  if (diferencia < 0) {
    diferencia = -1 * diferencia;
  }
  return diferencia;
}

int Dados::getLanzamientos1 () {
    return throws_d1_;
}

int Dados::getLanzamientos2 () {
  return throws_d2_;
}

float Dados::getMedia1 () {
  if (throws_d1_ == 0) {
    return 0;
  }
  addition_d1_ /= throws_d1_;
  return addition_d1_;
}

float Dados::getMedia2 () {
  if (throws_d2_ == 0) {
    return 0;
  }
  addition_d2_ /= throws_d2_;
  return addition_d2_;
}
