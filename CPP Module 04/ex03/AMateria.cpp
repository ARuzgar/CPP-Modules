#include "AMateria.hpp"


AMateria::AMateria(void){
	this->type = "";
}

AMateria::AMateria(std::string const & type){
	this->type = type;
}

AMateria::AMateria(AMateria const & src){
	*this = src;
}

AMateria::~AMateria(){
	return ;
}

AMateria& AMateria::operator=(const AMateria &other){
	this->type = other.type;
	return *this;
}

std::string const & AMateria::getType() const{
	return this->type;
}

void AMateria::use(ICharacter& target){
	std::cout << "AMateria " << this->type << " used on " << target.getName() << std::endl;
}