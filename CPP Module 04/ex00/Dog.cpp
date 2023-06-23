#include "Dog.hpp"

Dog::Dog(void)
{
	this->type = "Dog";
	std::cout << "a " << type <<" is born." << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(const Dog &other)
{
	*this = other;
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	this->type = other.type;
	std::cout << "Dog assignation operator called" << std::endl;
	return (*this);

}
void Dog::makeSound() const
{
	std::cout << "Woof woof WHITE!!!" << std::endl;
}