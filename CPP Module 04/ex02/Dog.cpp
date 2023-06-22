#include "Dog.hpp"

Dog::Dog()
{
	this->type = "Dog";
	this->brain = new Brain();
	std::cout << "a " << type <<" is born." << std::endl;
}

Dog::Dog(const Dog &copy){
	*this = copy;
}

Dog::~Dog(void)
{
	delete this->brain;
	std::cout << type << " died." << std::endl;
}

Dog &	Dog::operator=(Dog const & dog)
{
	this->type = dog.type;
	this->brain = new Brain;
	std::cout << "A" << dog.type << " is clonned." << std::endl;
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "Woof woof WHITE!!!" << std::endl;
}