#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>
# include "AMateria.hpp"

class Ice : public AMateria
{
	public:
	Ice(void);
	Ice(std::string const & type);
	Ice(Ice const & src);
	~Ice();
	Ice &operator=(const Ice &other);
	std::string const & getType() const;
	Ice* clone() const;
	void use(ICharacter& target);
};

#endif