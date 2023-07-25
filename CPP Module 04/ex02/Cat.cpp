#include "Cat.hpp"

Cat::Cat(void){
	this->type = "Cat";
	this->brain = new Brain();
	std::cout << "A " << this->type <<" is born." << std::endl;
}

Cat::Cat(const Cat &copy){
	std::cout << "An " << copy.type << " is being clonned." << std::endl;	
	*this = copy;
}

Cat &	Cat::operator=(Cat const &otherCat){
	this->type = otherCat.type;
	this->brain = new Brain(*otherCat.brain);
	std::cout << "A " << otherCat.type << " is clonned." << std::endl;
	return (*this);
}

Cat::~Cat(void){
	std::cout << this->type << " died..." << std::endl;
	delete brain;
}

void Cat::makeSound() const{
	std::cout << "Meow meow NIGGA!!!" << std::endl;
}