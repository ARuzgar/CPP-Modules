#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include "ICharacter.hpp"

class AMateria
{
protected:
	std::string type;

public:
	AMateria(void);
	AMateria(std::string const & type);
	AMateria(AMateria const & copy);
	virtual ~AMateria();
	virtual AMateria &operator=(const AMateria &other);
	std::string const & getType() const;
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};

#endif