#include "WrongCat.hpp"

WrongCat::WrongCat(){
	this->type = "WrongCat";
	std::cout << this->type << " constructor called" << std::endl;
}

WrongCat::~WrongCat(){
	std::cout << this->type << " destructor called" << std::endl;
}

void    WrongCat::makeSound() const{
	std::cout << "Woof falan işte!" << std::endl;
}