#include "Cat.hpp"

Cat::Cat(void){
	this->type = "Cat";
	std::cout << "A " << type <<" is born." << std::endl;
}

Cat::Cat(const Cat &copy){
	std::cout << "A" << copy.type << " is being clonned." << std::endl;
	*this = copy;
}

Cat &Cat::operator=(const Cat &otherCat){
	this->type = otherCat.type;
	std::cout << "A" << otherCat.type << " is clonned." << std::endl;
	return (*this);
}

Cat::~Cat(){
	std::cout << this->type << " died..." << std::endl;
}

void Cat::makeSound() const{
	std::cout << "Meow meow NIGGA!!!" << std::endl;
}