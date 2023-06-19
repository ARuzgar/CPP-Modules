#include "FragTrap.hpp"

FragTrap::FragTrap(){
	static int i;
	std::stringstream Fraggy;
	std::string temp;
	Fraggy << i;
	Fraggy >> temp;
	name = std::string("FR4G-TP " + temp);
	hitPoints = 100;
	maxHP = 100;
	energyPoints = 100;
	attackDamage = 30;
	std::cout << "<FragTrap> " << name << " is assembled." << std::endl;
	i++;
}

FragTrap::FragTrap(std::string name){
	this->name = "FR4G-TP " + name;
	hitPoints = 100;
	maxHP = 100;
	energyPoints = 100;
	attackDamage = 30;
	std::cout << "<FragTrap> " << this->name << " is assembled." << std::endl;
}

FragTrap::~FragTrap(){
	std::cout << this->name << " is destroyed." << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << name << " gives out the highest of the fives!" << std::endl;
}
