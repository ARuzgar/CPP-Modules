#include "MateriaSource.hpp"

//Constructor
MateriaSource::MateriaSource(){
	for(int i = 0; i < 4; i++)
		this->slots[i] = NULL;
	std::cout << "Materia Source is constructed." << std::endl;
}

//Copy Constructor a.k.a. Function Overload
MateriaSource::MateriaSource( MateriaSource const & copy){
	*this = copy;
}

//Operator Overload, Deep Copies slots via Clone Method of Materia's.
MateriaSource&	MateriaSource::operator=( MateriaSource const & otherMateriaSource){
	for(int i = 0; i < 4; i++){
		if (this->slots[i]){
			delete this->slots[i];
		}
		this->slots[i] = otherMateriaSource.slots[i]->clone();
	}
	return *this;
}

//Destructor
MateriaSource::~MateriaSource(){
	for(int i = 0; i < 4; i++)
		if (this->slots[i])
			delete this->slots[i];
	std::cout << "Materia Source is destroyed." << std::endl;
}

//New Materia Creating Spell of the MateriaSource entity. 
//It can only create a new Materia if it knows it beforehand. 
//It returns a Clone of the Materia that it has in its slots via Materia's Clone method.
//Basically It's a Deep Copy.
AMateria*	MateriaSource::createMateria( std::string const & type ){
	for ( int i = 0; i < 4; i++ )
        if ( this->slots[i] && this->slots[i]->getType() == type )
            return this->slots[i]->clone();
    return 0;
}

//It's almost the same with Equip Method of Charater's
//Since its an Magical Entity that can learn and "Create"(clone) new Materia's that it already has its "Learn" instead of "Equip".
void	MateriaSource::learnMateria( AMateria* m){
	for (int i = 0; i < 4; i++)
	{
        if (!this->slots[i]){
            this->slots[i] = m;
			std::cout << "Materia " << m->getType() << " has been learned by MateriaSource" << std::endl;
            break;
        }
		else if(i == 4){
			for(int j = 0; j < 2147483646; j++){
				if (!this->leftToTheGround[j]){
					this->leftToTheGround[j] = m;
				}
			}
			std::cout << "MateriaSource's slots are full and the Materia left to the ground" << std::endl;
		}
	}
}