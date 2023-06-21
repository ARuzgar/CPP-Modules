#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource{
private:
	AMateria*       slots[4];

public:
	MateriaSource();
	~MateriaSource();
	MateriaSource( MateriaSource const & copy);

	MateriaSource&  operator=( MateriaSource const & other);
	AMateria*       createMateria( std::string const & type );
	void            learnMateria( AMateria* m);
};

#endif