/*------------------------------------------------------------------------------
Practice 1 Exercise 3
dados.h
In this file is declared the class 'Dados' and all its methods
------------------------------------------------------------------------------*/

#ifndef DADOS_H
#define DADOS_H

class Dados {
  private:
    int d1_;  //Dice 1
    int d2_;  //Dice 2
    //Used for getLanzamientos1/2
    int throws_d1_;
    int throws_d2_;
    //Used for getMedia1/2
    float average_d1_;
    float average_d2_;
  public:
    //Constructor: initiate seed and set d1_ and d2_ to '1'
    Dados();
    //returns data in d1_/d2_
    int getDado1();
    int getDado2();
    //returns "false" if 'n' is not from 1 to 6
    //returns "true" if 'n' is correct and save it in d1_/d2_
    bool setDado1(int n);
    bool setDado2(int n);
    //assign pseudorandom numbers to d1_ and d2_
    void lanzamiento();
    //returns d1_ + d2_
    int getSuma();
    //returns | d1_ - d2_ |
    int getDiferencia();
    //returns number of executions of lanzamiento() or setDado1/2
    int getLanzamientos1();
    int getLanzamientos2();
    //returns average of d1/d2 throws
    float getMedia1();
    float getMedia2();
};

#endif
