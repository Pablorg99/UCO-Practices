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
  //Don't necessary provide array size with an initializer list
  //C++ will counter the number of elements and make the array that size
  d1_[0] = 1;
  d2_[0] = 1;
  for (int i = 1; i < 5; i++) {
    d1_[i] = 0;
    d2_[i] = 0;
  }
  throws_d1_ = 0;
  throws_d2_ = 0;
  addition_d1_ = 0;
  addition_d2_ = 0;
}

bool Dados::setDado1 (int n) {
  if (n < 1 || n > 6) return false;
  else {
    for (int i = 4; i > 0; i--) {
      d1_[i] = d1_[i - 1];
    }
    d1_[0] = n;
    throws_d1_++;
    addition_d1_ += getDado1();
    return true;
  }
}

bool Dados::setDado2 (int n) {
  if (n < 1 || n > 6) return false;
  else {
    for (int i = 4; i > 0; i--) {
      d2_[i] = d2_[i - 1];
    }
    d2_[0] = n;
    throws_d2_++;
    addition_d2_ += getDado2();
    return true;
  }
}

void Dados::lanzamiento () {
  for (int i = 4; i > 0; i--) {
    d1_[i] = d1_[i - 1];
    d2_[i] = d2_[i - 1];
  }
  d1_[0] = (rand() % 6) + 1;
  d2_[0] = (rand() % 6) + 1;
  throws_d1_++;
  throws_d2_++;
  addition_d1_ += getDado1();
  addition_d2_ += getDado2();
}

int Dados::getDiferencia () const {
  int diferencia;
  diferencia = getDado1() - getDado2();
  if (diferencia < 0) {
    diferencia = -1 * diferencia;
  }
  return diferencia;
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

void Dados::getUltimos1 (int (&vector) [5]) {
  for (int i = 0; i < 5; i++) {
    vector[i] = d1_[i];
  }
}

void Dados::getUltimos2 (int (&vector) [5]) {
  for (int i = 0; i < 5; i++) {
    vector[i] = d2_[i];
  }
}
