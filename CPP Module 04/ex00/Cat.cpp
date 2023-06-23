#include "Cat.hpp"

Cat::Cat(void)
{
	this->type = "Cat";
	std::cout << "a " << type <<" is born." << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(const Cat &copy)
{
	*this = copy;
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &cat)
{
	this->type = cat.type;
	std::cout << "A" << cat.type << " is clonned." << std::endl;
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "Meow meow NIGGA!!!" << std::endl;
}