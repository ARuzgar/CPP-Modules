#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure"){
	//std::cout << "Cure Materia Created."
}

Cure::Cure(Cure const & src) : AMateria("cure"){
	*this = src;
	//std::cout << "Cure Materia copied."
}

Cure::~Cure(){
	//std::cout << "Cure Materia destroyed."
}

Cure &	Cure::operator=(const Cure &other){
    this->type = other.type;
    return *this;
}

Cure*	Cure::clone() const{
	std::cout << "Cure Materia Clonned." << std::endl;
	return (new Cure(*this));
}

void	Cure::use(ICharacter& target){
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}