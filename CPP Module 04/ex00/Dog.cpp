#include "Dog.hpp"

Dog::Dog(void)
{
	this->type = "Dog";
	std::cout << "a " << type <<" is born." << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Woof woof WHITE!!!" << std::endl;
}