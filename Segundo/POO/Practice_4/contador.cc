/*-----------------------------------------------------------------------------------------------------
Pablo Rodríguez Guillén
contador.cc
File with the implementation of the different methods of the class Contador.
-----------------------------------------------------------------------------------------------------*/

#include "contador.h"

Contador::Contador(int value = 0, int min = 0, int max = 1000) {
    if(value < min || value > max || min > max) {
        value_ = 0;
        min_ = 0;
        max_ = 1000;
    }
    else {
        value_ = value;
        min_ = min;
        max_ = max;
    }
}

Contador Contador::operator=(int integer) {
    if (integer < min_) value_ = min_;
    else if (integer > max_) value_ = max_;
    else value_ = integer;
    return *this;
}

Contador Contador::operator++(void) {
	if((this->get() + 1) > max_) return *this; 
	else {
		++value_;
		return *this;
	}
}
Contador Contador::operator++(int) {
	Contador temp = *this;
	if((this->get() + 1) > max_) return temp; 
	else {
		++value_;
		return temp;
	}
}
Contador Contador::operator--(void) {
	if((this->get() - 1) < min_) return *this; 
	else {
		--value_;
		return *this;
	}
}
Contador Contador::operator--(int) {
	Contador temp = *this;
	if((this->get() - 1) < min_) return temp; 
	else {
		++value_;
		return temp;
	}
}

Contador Contador::operator+(int addition) {
	if((this->get() + addition) > max_) value_ = max_;
	else value_ += addition;
	return *this;
}
Contador Contador::operator-(int substraction) {
	if((this->get() -substraction) < min_) value_ = min_;
	else value_ -= substraction;
	return *this;
}

Contador operator+(int addition, Contador &counter) {
	if((counter.get() + addition) > counter.max_) counter.value_ = counter.max_;
	else counter.value_ += addition;
	return counter;
}
Contador operator-(int substraction, Contador &counter) {
	if((counter.get() - substraction) > counter.min_) counter.value_ = counter.min_;
	else counter.value_ += substraction;
	return counter;
}