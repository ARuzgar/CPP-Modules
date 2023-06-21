#include "MateriaSource.hpp"

MateriaSource::MateriaSource(){
	for(int i = 0; i < 4; i++)
		this->slots[i] = NULL;
}

MateriaSource::~MateriaSource(){
	for(int i = 0; i < 4; i++)
		if (this->slots[i])
			delete this->slots[i];
}

MateriaSource::MateriaSource( MateriaSource const & copy){
	*this = copy;
}

MateriaSource&	MateriaSource::operator=( MateriaSource const & other){
	for(int i = 0; i < 4; i++){
		if (this->slots[i]){
			delete this->slots[i];
		}
		this->slots[i] = other.slots[i];
	}
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
            break;
        }
}