/*------------------------------------------------------------------------------
Practice 1 Exercise 3
dados.h
In this file, the function main declarates a variable from the class 'Dados' and
call all the methods of the class.
------------------------------------------------------------------------------*/

#include <iostream>
#include "dados.h"

int main() {
  using std::cout;
  using std::cin;
  Dados d;
  int aux;  //used to save values introduced by keyboard

  //Values after declaring the variable
  //Prints Dices' value and their addition
  cout << "Dice 1 = " << d.getDado1() << '\n';
  cout << "Dice 2 = " << d.getDado2() << '\n';
  cout << "Addition = " << d.getSuma() << '\n';

  //Values after calling 'lanzamiento' to roll the dices
  cout << endl << "Rolling dices..." << '\n';
  d.lanzamiento();
  //Print Dices' values and their addition
  cout << "Dice 1 = " << d.getDado1() << '\n';
  cout << "Dice 2 = " << d.getDado2() << '\n';
  cout << "Addition = " << d.getSuma() << '\n';

  //Values assignment by keyboard
  cout << endl << "Assign values manually to the dices:" << '\n';

  //Dice 1
  cout << "Value for Dice 1: ";
  cin >> aux;
  //The user is in the while loop until he introduces a correct number (1 to 6)
  //When 'aux' is correct, setDado1 returns "true" and save 'aux' in d1_
  //Same for Dice 2
  while (d.setDado1(aux) == false) {
    cout << "The value is not between 1 and 6, introduce another one: ";
    cin >> aux;
  }
  cout << aux << " saved in Dice 1." << '\n';
  //Dice 2
  cout << "Value for Dice 2: ";
  cin >> aux;
  while (d.setDado2(aux) == false) {
    cout << "The value is not between 1 and 6, introduce another one: ";
    cin >> aux;
  }
  cout << aux << " saved in Dice 2" << '\n';

  //Prints Dices' value and their addition
  cout << "Dice 1 = " << d.getDado1() << '\n';
  cout << "Dice 2 = " << d.getDado2() << '\n';
  cout << "Addition = " << d.getSuma() << '\n';

  return 0;
}
