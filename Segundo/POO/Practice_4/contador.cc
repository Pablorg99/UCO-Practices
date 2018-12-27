/*-----------------------------------------------------------------------------------------------------
Pablo Rodríguez Guillén
contador.cc
File with the implementation of the different methods of the class Contador.
-----------------------------------------------------------------------------------------------------*/

#include "contador.h"

Contador::Contador(int value, int min, int max) {
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
	operations_.emplace_back(get());
}

Contador Contador::operator=(int integer) {
    if (integer < min_) value_ = min_;
    else if (integer > max_) value_ = max_;
    else value_ = integer;
	operations_.emplace_back(get());
    return *this;
}

Contador Contador::operator++(void) {
	if((this->get() + 1) > max_) return *this; 
	else {
		++value_;
		operations_.emplace_back(get());
		return *this;
	}
}
Contador Contador::operator++(int) {
	Contador temp = *this;
	if((this->get() + 1) > max_) return temp; 
	else {
		++value_;
		operations_.emplace_back(get());
		return temp;
	}
}
Contador Contador::operator--(void) {
	if((this->get() - 1) < min_) return *this; 
	else {
		--value_;
		operations_.emplace_back(get());
		return *this;
	}
}
Contador Contador::operator--(int) {
	Contador temp = *this;
	if((this->get() - 1) < min_) return temp; 
	else {
		--value_;
		operations_.emplace_back(get());
		return temp;
	}
}

Contador Contador::operator+(int addition) {
	if((this->get() + addition) > max_) value_ = max_;
	else value_ += addition;
	operations_.emplace_back(get());
	return *this;
}
Contador Contador::operator-(int substraction) {
	if((this->get() -substraction) < min_) value_ = min_;
	else value_ -= substraction;
	operations_.emplace_back(get());
	return *this;
}

Contador operator+(int addition, Contador &counter) {
	if((counter.get() + addition) > counter.max_) counter.value_ = counter.max_;
	else counter.value_ += addition;
	counter.operations_.emplace_back(counter.get());
	return counter;
}
Contador operator-(int substraction, Contador &counter) {
	if((substraction - counter.get()) < counter.min_) counter.value_ = counter.min_;
	else counter.value_ -= substraction;
	counter.operations_.emplace_back(counter.get());
	return counter;
}

bool Contador::undo(int n_operations) {
	int highest_accesible_position = operations_.size() - 1;
	/*The number of operations to undo has to be between the first and the
	last position with content of the vector (0, highest accesible position)*/
	if((n_operations <= highest_accesible_position) && (n_operations > 0)) {
		value_ = operations_[highest_accesible_position - n_operations];
		operations_.resize(highest_accesible_position - n_operations);
		return true;
	}
	else return false;
}