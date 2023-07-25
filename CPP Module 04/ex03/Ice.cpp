#include "Ice.hpp"

//Constructor
Ice::Ice(void) : AMateria("ice"){
	//std::cout << "Ice Materia Created."
}

//Copy Constructor a.k.a. Function Overload
Ice::Ice(Ice const & copy) : AMateria("ice"){
	//std::cout << "Ice Materia copied."
	*this = copy;
}

//Operator Overload
Ice &	Ice::operator=(const Ice &otherIce){
    this->type = otherIce.type;
    return *this;
}

//Destructor
Ice::~Ice(){
	//std::cout << "Ice Materia destroyed."
}

//Clone Method for deep copying at Character's or MateriaSources Operator Overload
Ice*	Ice::clone() const{
	std::cout << "Ice Materia Clonned." << std::endl;
	return (new Ice(*this));
}

//For using Ice on target X
void	Ice::use(ICharacter& target){
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}