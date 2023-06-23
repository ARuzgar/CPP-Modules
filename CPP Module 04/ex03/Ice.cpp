#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice"){
	//std::cout << "Ice Materia Created."
}

Ice::Ice(Ice const & copy) : AMateria("ice"){
	*this = copy;
	//std::cout << "Ice Materia copied."
}

Ice::~Ice(){
	//std::cout << "Ice Materia destroyed."
}

Ice &	Ice::operator=(const Ice &ice){
    this->type = ice.type;
    return *this;
}

Ice*	Ice::clone() const{
	std::cout << "Ice Materia Clonned." << std::endl;
	return (new Ice(*this));
}

void	Ice::use(ICharacter& target){
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}