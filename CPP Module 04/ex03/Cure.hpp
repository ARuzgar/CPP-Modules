#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>
# include "AMateria.hpp"
# include "ICharacter.hpp"

class ICharacter;

class Cure : public AMateria
{
	public:
	Cure(void);
	Cure(std::string const & type);
	Cure(Cure const & src);
	~Cure();
	Cure &operator=(const Cure &other);
	std::string const & getType() const;
	Cure* clone() const;
	void use(ICharacter& target);
};

#endif