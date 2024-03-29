#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include "ICharacter.hpp"
# include "Ice.hpp"
# include "Cure.hpp"

class AMateria;
class ICharacter;

class Character : public ICharacter
{
	private:
		std::string name;
		AMateria *slots[4];
		void	*leftToTheGround[2147483646];

	public:
		Character(std::string const & name);
		Character(Character const &copy);
		Character &operator=(Character const &otherCharacter);
		~Character();

		std::string const & getName() const;
		void 				equip(AMateria* m);
		void 				unequip(int idx);
		void 				use(int idx, ICharacter& target);
};

#endif