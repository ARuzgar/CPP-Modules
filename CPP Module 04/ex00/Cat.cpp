#include "Cat.hpp"

Cat::Cat(void)
{
	this->type = "Cat";
	std::cout << "a " << type <<" is born." << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Meow meow NIGGA!!!" << std::endl;
}