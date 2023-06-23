#include "Dog.hpp"

Dog::Dog()
{
	this->type = "Dog";
	this->brain = new Brain();
	std::cout << "A " << type <<" is born." << std::endl;
}

Dog::~Dog(void)
{
	std::cout << type << " died." << std::endl;
	delete brain;
}

Dog::Dog(const Dog &other)
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = other;
}

Dog &	Dog::operator=(Dog const &dog)
{
	this->type = dog.type;
	this->brain = new Brain(*dog.brain);
	std::cout << "A " << dog.type << " is clonned." << std::endl;
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "Woof woof WHITE!!!" << std::endl;
}