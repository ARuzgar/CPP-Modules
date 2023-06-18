#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
	static int i;
	std::stringstream ss;
	std::string temp;
	ss << i;
	ss >> temp;
	name = std::string("ClapTrap " + temp);
	hitPoints = 10;
	maxHP = 10;
	energyPoints = 10;
	attackDamage = 0;
	std::cout << "<ClapTrap> " << name << " is created." << std::endl;
	i++;
}

ClapTrap::ClapTrap(std::string name)
{
	this->name = name;
	hitPoints = 10;
	maxHP = 10;
	energyPoints = 10;
	attackDamage = 0;
	std::cout << "<ClapTrap> " << this->name << " is created." << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &copy)
{
	std::cout << "Clap Trap is Clonned." << std::endl;
	*this = copy;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << this->name << " is destroyed." << std::endl;
}

ClapTrap &	ClapTrap::operator=(ClapTrap const &clapTrap)
{
	std::cout << "<ClapTrap> " << this->name << " stole " << clapTrap.name << "'s identity!" << std::endl;
	this->name = clapTrap.name;
	this->hitPoints = clapTrap.hitPoints;
	this->energyPoints = clapTrap.energyPoints;
	this->attackDamage = clapTrap.attackDamage;
	return (*this);
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->energyPoints > 0 && this->hitPoints > 0){
		std::cout << "<ClapTrap> " << this->name << " attacks " <<  target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
		this->energyPoints -= 1;
	}
	else if (this->hitPoints == 0)
		std::cout << "<ClapTrap> " << this->name << "needs to be repaired before trying to attack." << std::endl;
	else if (this->energyPoints == 0)
		std::cout << "<ClapTrap> " << this->name << "needs an energy boost before trying to attack." << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hitPoints = 0)
		std::cout << "Stop, he is already destroyed!" << std::endl;
	else{
		if (amount >= hitPoints){
			this->hitPoints = 0;
			std::cout << "<ClapTrap> " << this->name << " got blown away and destroyed by this hit." << std::endl;
		}
		else{
			this->hitPoints -= amount;
			std::cout << "<ClapTrap> " << this->name << " damaged " << amount << " points" << std::endl;
		}
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energyPoints > 0 && this->hitPoints < this->maxHP){
		this->energyPoints -= 1;
		if (amount >= (this->maxHP - this->hitPoints)){
			this->hitPoints = this->maxHP;
			std::cout << "<ClapTrap> " << this->name << " is replenished like a new!" << std::endl;
		}
		else{
			this->hitPoints += amount;
			std::cout << "<ClapTrap> " << this->name << " got new parts and repaired " << amount << " points." << std::endl;
		}
	}
	else if (this->energyPoints == 0)
		std::cout << "<ClapTrap> " << this->name << " needs an energy boost before trying to repair itself." << std::endl;
}

std::string	ClapTrap::getName(void){
	return this->name;
}

int	ClapTrap::getAttackDamage(void){
	return this->attackDamage;
}
