#include "Animal.hpp"

Animal::Animal(void){
	this->type = "Animal";
	std::cout << "An " << type <<" is born." << std::endl;
}

Animal::Animal(Animal const &copy){
	std::cout << "An " << copy.type << " is being clonned." << std::endl;
	*this = copy;
}

Animal &	Animal::operator=(Animal const &otherAnimal){
	this->type = otherAnimal.type;
	std::cout << "An " << otherAnimal.type << " is clonned." << std::endl;
	return (*this);
}

Animal::~Animal(void){
	std::cout <<"Animal died." << std::endl;
}

void	Animal::makeSound() const{
		std::cout << "Undefined Animals Can't Cast Sounds." << std::endl;
}

std::string Animal::getType() const{
	return (this->type);
}