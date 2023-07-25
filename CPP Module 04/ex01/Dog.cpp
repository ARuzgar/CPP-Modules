#include "Dog.hpp"

Dog::Dog(){
	this->type = "Dog";
	this->brain = new Brain();
	std::cout << "A " << type <<" is born." << std::endl;
}

Dog::Dog(const Dog &copy){
	std::cout << "An " << copy.type << " is being clonned." << std::endl;
	*this = copy;
}

Dog &	Dog::operator=(Dog const &otherDog){
	this->type = otherDog.type;
	this->brain = new Brain(*otherDog.brain);
	std::cout << "A " << otherDog.type << " is clonned." << std::endl;
	return (*this);
}

Dog::~Dog(void){
	std::cout << this->type << " died." << std::endl;
	delete brain;
}

void Dog::makeSound() const{
	std::cout << "Woof woof WHITE!!!" << std::endl;
}