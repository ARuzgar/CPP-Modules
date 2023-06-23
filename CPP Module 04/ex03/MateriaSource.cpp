#include "MateriaSource.hpp"

MateriaSource::MateriaSource(){
	for(int i = 0; i < 4; i++)
		this->slots[i] = NULL;
	std::cout << "Materia Source is constructed." << std::endl;
}

MateriaSource::~MateriaSource(){
	for(int i = 0; i < 4; i++)
		if (this->slots[i])
			delete this->slots[i];
	std::cout << "Materia Source is destroyed." << std::endl;
}

MateriaSource::MateriaSource( MateriaSource const & copy){
	*this = copy;
}

MateriaSource&	MateriaSource::operator=( MateriaSource const & other){
	for(int i = 0; i < 4; i++){
		if (this->slots[i]){
			delete this->slots[i];
		}
		this->slots[i] = other.slots[i]->clone();
	}
	return *this;
}

AMateria*	MateriaSource::createMateria( std::string const & type ){
	for ( int i = 0; i < 4; i++ )
        if ( this->slots[i] && this->slots[i]->getType() == type )
            return this->slots[i]->clone();
    return 0;
}

void	MateriaSource::learnMateria( AMateria* m){
	for (int i = 0; i < 4; i++)
        if (!this->slots[i]){
            this->slots[i] = m;
			std::cout << "Materia " << m->getType() << " has been learned by MateriaSource" << std::endl;
            break;
        }
}