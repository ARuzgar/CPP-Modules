#include "Dog.hpp"

Dog::Dog(void){
	this->type = "Dog";
	std::cout << "A " << type <<" is born." << std::endl;
}

Dog::Dog(const Dog &copy){
	std::cout << "A" << copy.type << " is being clonned." << std::endl;
	*this = copy;
}

Dog &Dog::operator=(const Dog &otherDog){
	this->type = otherDog.type;
	std::cout << "A" << otherDog.type << " is clonned." << std::endl;
	return (*this);
}

Dog::~Dog(){
	std::cout << this->type << " died..." << std::endl;
}

void Dog::makeSound() const{
	std::cout << "Woof woof WHITE!!!" << std::endl;
}