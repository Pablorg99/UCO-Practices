/*------------------------------------------------------------------------------
Practice 1 Exercise 3
dados.h
In this file is declared the class 'Dados' and all its methods
------------------------------------------------------------------------------*/

#ifndef DADOS_H
#define DADOS_H

class Dados {
  private:
    //Able to save last 5 values (d[0] last value obtained for dice)
    int d1_[5];  //Dice 1
    int d2_[5];  //Dice 2
    //Used for getLanzamientos1/2
    int throws_d1_;
    int throws_d2_;
    //Used for getMedia1/2
    float addition_d1_;
    float addition_d2_;
  public:
    //Constructor: initiate seed and set d1_ and d2_ to '1'
    Dados();
    //returns data in d1_/d2_
    int getDado1() const {return d1_;}
    int getDado2() const {return d2_;}
    //returns "false" if 'n' is not from 1 to 6
    //returns "true" if 'n' is correct and save it in d1_[0]/d2_[0]
    bool setDado1(int n);
    bool setDado2(int n);
    //assign pseudorandom numbers to d1_ and d2_
    void lanzamiento();
    //returns d1_ + d2_
    int getSuma() const {return getDado1() + getDado2();}
    //returns | d1_ - d2_ |
    int getDiferencia() const;
    //returns number of executions of lanzamiento() or setDado1/2
    int getLanzamientos1() const {return throws_d1_;}
    int getLanzamientos2() const {return throws_d2_;}
    //returns average of d1/d2 throws
    float getMedia1() const;
    float getMedia2() const;
    //saves in array the last 5 values from the dices
    void getUltimos1 (int &lasts5_d1_);
    void getUltimos2 (int &lasts5_d2_);
};

#endif
