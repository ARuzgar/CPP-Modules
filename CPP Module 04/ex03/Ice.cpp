#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice"){
	//std::cout << "Ice Materia Created."
}

Ice::Ice(Ice const & src) : AMateria("ice"){
	*this = src;
	//std::cout << "Ice Materia copied."
}

Ice::~Ice(){
	//std::cout << "Ice Materia destroyed."
}

Ice &	Ice::operator=(const Ice &other){
    this->type = other.type;
    return *this;
}

Ice*	Ice::clone() const{
	return (new Ice(*this));
	//std::cout << "Ice Materia Clonned."
}

void	Ice::use(ICharacter& target){
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}