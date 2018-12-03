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
        or min higher than max, Contador is set with default values (0, 0, 1000*/ 
        Contador(int value = 0, int min = 0, int max = 1000);
        //Getter
        inline int get() {return value_;}
        //Called when Contador c = integer
        /*Returns the Contador object who called the function and
        assign integer to value_ if the integer is betweem min and max*/
        Contador operator=(int integer);
        //Contador c = Contador d is not necessary to do, because is the default = operator
        //Unary Operators
        //NEED TO FIX (check_?)
        inline Contador operator++(void);
        inline Contador operator++(int);
        inline Contador operator--(void);
        inline Contador operator--(int);
};

#endif