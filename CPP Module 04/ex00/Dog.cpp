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

Dog::Dog(const Dog &copy)
{
	*this = copy;
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &dog)
{
	this->type = dog.type;
	std::cout << "A" << dog.type << " is clonned." << std::endl;
	return (*this);

}
void Dog::makeSound() const
{
	std::cout << "Woof woof WHITE!!!" << std::endl;
}