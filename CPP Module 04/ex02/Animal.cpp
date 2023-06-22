#include "Animal.hpp"

Animal::~Animal(){
}

void Animal::makeSound() const{
	std::cout << "Undefined Animals Can't Cast Sounds." << std::endl;
}

std::string Animal::getType() const{
	return (this->type);
}