#include "Animal.hpp"

Animal::Animal(void)
{
	this->type = "Animal";
	std::cout << "a " << type <<" is born." << std::endl;
}

Animal::Animal(Animal const &copy)
{
	std::cout << "A" << copy.type << " is being clonned." << std::endl;	
	*this = copy;
}

Animal::~Animal(void)
{
	std::cout <<"Animal died." << std::endl;
}

Animal &	Animal::operator=(Animal const &animal)
{
	this->type = animal.type;
	std::cout << "a" << animal.type << " is clonned." << std::endl;
	return (*this);
}

void	Animal::makeSound() const
{
		std::cout << "Undefined Animals Can't Cast Sounds." << std::endl;
}

std::string Animal::getType() const
{
	return (this->type);
}