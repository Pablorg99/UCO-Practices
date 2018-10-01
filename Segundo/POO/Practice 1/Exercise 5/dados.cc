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
  d1_ = {1, 0, 0, 0, 0};
  d2_ = {1, 0, 0, 0, 0};
  throws_d1_ = 0;
  throws_d2_ = 0;
  addition_d1_ = 0;
  addition_d2_ = 0;
}

bool Dados::setDado1 (int n) {
  if (n < 1 || n > 6) return false;
  else {
    for (int i = 4; i > 0; i++) {
      d1_[i] = d1_[i - 1];
    }
    d1_[0] = n;
    throws_d1_++;
    addition_d1_ += d1_;
    return true;
  }
}

bool Dados::setDado2 (int n) {
  if (n < 1 || n > 6) return false;
  else {
    for (int i = 4; i > 0; i++) {
      d1_[i] = d1_[i - 1];
    }
    d1_[0] = n;
    throws_d2_++;
    addition_d2_ += d2_;
    return true;
  }
}

void Dados::lanzamiento () {
  for (int i = 4; i > 0; i++) {
    d1_[i] = d1_[i - 1];
    d2_[i] = d2_[i - 1];
  }
  d1_[0] = (rand() % 6) + 1;
  d2_[0] = (rand() % 6) + 1;
  throws_d1_++;
  throws_d2_++;
  addition_d1_ += d1_;
  addition_d2_ += d2_;
}

int Dados::getDiferencia () const {
  int diferencia;
  diferencia = getDado1() - getDado2();
  if (diferencia < 0) {
    diferencia = -1 * diferencia;
  }
  return diferencia;
}


float Dados::getMedia1 () const {
  if (throws_d1_ == 0) {
    return 0;
  }
  addition_d1_ /= throws_d1_;
  return addition_d1_;
}

float Dados::getMedia2 () const {
  if (throws_d2_ == 0) {
    return 0;
  }
  addition_d2_ /= throws_d2_;
  return addition_d2_;
}

void getUltimos1 (int &vector) {
  for (int i = 0; i < 5; i++) {
    vector = d1_;
  }

void getUltimos1 (int &vector) {
  for (int i = 0; i < 5; i++) {
    vector = d2_;
  }
}
