#include "contador.h"

Contador::Contador(int value = 0, int min = 0, int max = 1000) {
    if(value <= min || value >= max || min > max) {
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
	if((value_ + 1) > max) return *this; 
	else {
		++value_;
		return *this;
	}
}
Contador Contador::operator++(int) {
	++value_; return *this;
}
Contador Contador::operator--(void) {
	--value_; return *this;
}
Contador Contador::operator--(int) {
	--value_; return *this;
}