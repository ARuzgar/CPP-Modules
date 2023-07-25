#include "AMateria.hpp"

//Constructor
AMateria::AMateria(void){
	this->type = "";
}

//Function Overload Constructor
AMateria::AMateria(std::string const & type){
	this->type = type;
}

//Copy Constructor a.k.a. Function Overload
AMateria::AMateria(AMateria const & copy){
	*this = copy;
}

//Operator Overload
AMateria& AMateria::operator=(const AMateria &otherAMateria){
	this->type = otherAMateria.type;
	return *this;
}

//Destructor
AMateria::~AMateria(){
	return ;
}

//Setter-Getter's Getter
std::string const & AMateria::getType() const{
	return this->type;
}

//Use on &X target
void AMateria::use(ICharacter& target){
	std::cout << "AMateria " << this->type << " used on " << target.getName() << std::endl;
}