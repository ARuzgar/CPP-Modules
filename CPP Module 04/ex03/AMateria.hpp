#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include "ICharacter.hpp"

class ICharacter;

//Abstract Materia
class AMateria
{
protected:
	std::string type;

public:
	AMateria(void);
	AMateria(std::string const & type);
	AMateria(AMateria const & copy);
	virtual AMateria &operator=(const AMateria &otherAMateria);
	virtual ~AMateria();

	std::string const & getType() const;
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};

#endif