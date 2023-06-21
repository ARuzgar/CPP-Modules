#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure"){
	
}

Cure::Cure(Cure const & src) : AMateria("cure"){
	*this = src;
}

Cure::~Cure(){
	
}

Cure &	Cure::operator=(const Cure &other){
    this->type = other.type;
    return *this;
}

Cure*	Cure::clone() const{
	return (new Cure(*this));
}

void	Cure::use(ICharacter& target){
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}