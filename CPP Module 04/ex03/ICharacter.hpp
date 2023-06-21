#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

# include <iostream>

class ICharacter
{
	public:
		ICharacter(void);
		ICharacter();
		ICharacter(ICharacter const &instance);
		ICharacter &operator=(ICharacter const &rhs);
		~ICharacter(void);
		std::string getName();

	private:

};

#endif