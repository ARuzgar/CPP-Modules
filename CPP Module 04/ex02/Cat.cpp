#include "Cat.hpp"

Cat::Cat(void)
{
	this->type = "Cat";
	this->brain = new Brain();
	std::cout << "a " << type <<" is born." << std::endl;
}

Cat::~Cat(void)
{
	std::cout << type << " died." << std::endl;
	delete brain;
}

Cat::Cat(const Cat &copy){
	std::cout << "Cat copy constructor called" << std::endl;
	*this = copy;
}

Cat &	Cat::operator=(Cat const &cat)
{
	this->type = cat.type;
	this->brain = new Brain;
	std::cout << "A " << cat.type << " is clonned." << std::endl;
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "Meow meow NIGGA!!!" << std::endl;
}