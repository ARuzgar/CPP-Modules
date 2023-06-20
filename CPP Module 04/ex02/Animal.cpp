#include "Animal.hpp"

Animal::~Animal()
{
	std::cout << "Animal died." << std::endl;
}

void Animal::makeSound() const
{
	std::cout << "Undefined Animals Can't Cast Sounds." << std::endl;
}

std::string Animal::getType() const
{
	return (this->type);
}