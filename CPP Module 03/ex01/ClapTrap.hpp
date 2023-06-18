#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <sstream>

class ClapTrap{
private:
	std::string 	name;
	unsigned int	hitPoints;
	unsigned int	maxHP;
	unsigned int	energyPoints;
	unsigned int	attackDamage;

public:
	ClapTrap(void);
	ClapTrap(std::string name);
	ClapTrap(ClapTrap const &copy);
	ClapTrap &operator=(ClapTrap const &clapTrap);
	~ClapTrap(void);
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	std::string getName(void);
	int getAttackDamage(void);
};

#endif