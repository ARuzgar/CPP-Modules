#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>
# include "AMateria.hpp"
# include "ICharacter.hpp"

class ICharacter;

class Ice : public AMateria
{
	public:
	Ice(void);
	Ice(std::string const & type);
	Ice(Ice const & copy);
	Ice &operator=(const Ice &other);
	~Ice();

	std::string const & getType() const;
	Ice* clone() const;
	void use(ICharacter& target);
};

#endif