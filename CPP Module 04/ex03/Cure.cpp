#include "Cure.hpp"

//Constructor
Cure::Cure(void) : AMateria("cure"){
	//std::cout << "Cure Materia Created."
}

//Copy Constructor a.k.a. Function Overload
Cure::Cure(Cure const & copy) : AMateria("cure"){
	//std::cout << "Cure Materia copied."
	*this = copy;
}

//Operator Overload
Cure &	Cure::operator=(const Cure & otherCure){
    this->type = otherCure.type;
    return *this;
}

//Destructor
Cure::~Cure(){
	//std::cout << "Cure Materia destroyed."
}

//Clone Method for deep copying at Character's or MateriaSources Operator Overload
Cure*	Cure::clone() const{
	std::cout << "Cure Materia Clonned." << std::endl;
	return (new Cure(*this));
}

//For using Cure on target X
void	Cure::use(ICharacter& target){
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}