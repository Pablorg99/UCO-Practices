/*-----------------------------------------------------------------------------------------------------
Pablo Rodríguez Guillén
contador.h
Header file of the class Contador and its methods
-----------------------------------------------------------------------------------------------------*/

#ifndef CONTADOR_H
#define CONTADOR_H

class Contador {
    public:
        int value_;
        int min_;
        int max_;
    private:
        //Constructor
        /*If there are logical errors like: value lower or higher than min or max
        or min higher than max, Contador is set with default values (0, 0, 1000)*/ 
        Contador(int value = 0, int min = 0, int max = 1000);
        //Getter
        inline int get() {return value_;}
        //Called when Contador c = integer
        /*Returns the Contador object who called the function and
        assign integer to value_ if the integer is betweem min and max*/
        Contador operator=(int integer);
        //Contador c = Contador d is not necessary to do, because is the default = operator
        //Unary Operators
        Contador operator++(void); //++c
        Contador operator++(int); //c++
        Contador operator--(void); //--c
        Contador operator--(int); //c--
		//Binary Operators (counter +/- integer)
		Contador operator+(int addition);
		Contador operator-(int substraction);
		/*Binary operators like: integer +/- counter, should be declared as non-member
		functions of the class, I declare them as friend to be able to use the get() method*/
		friend Contador operator+(int addition, Contador &counter);
		friend Contador operator-(int substraction, Contador &counter);
};

#endif