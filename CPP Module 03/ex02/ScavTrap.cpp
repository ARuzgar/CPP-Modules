#include "ScavTrap.hpp"

ScavTrap::ScavTrap(){
	static int i;
	std::stringstream scavvy;
	std::string temp;
	scavvy << i;
	scavvy >> temp;
	name = std::string("SC4V-TP " + temp);
	hitPoints = 100;
	maxHP = 100;
	energyPoints = 50;
	attackDamage = 20;
	std::cout << "<ScavTrap> " << name << " is assembled." << std::endl;
	i++;
}

ScavTrap::ScavTrap(std::string name){
	this->name = "SC4V-TP " + name;
	hitPoints = 100;
	maxHP = 100;
	energyPoints = 50;
	attackDamage = 20;
	std::cout << "<ScavTrap> " << this->name << " is assembled." << std::endl;
}

ScavTrap::~ScavTrap(){
	std::cout << this->name << " is destroyed." << std::endl;
}

void	ScavTrap::guardGate(){
	std::cout << "<ScavTrap> " << name << " is now in Gate keeper mode." << std::endl;
}

void	ScavTrap::attack(const std::string &target){
	if (this->energyPoints > 0 && this->hitPoints > 0){
		std::cout << "<ScavTrap> " << this->name << " attacks " <<  target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
		this->energyPoints -= 1;
	}
	else if (this->hitPoints == 0)
		std::cout << "<ScavTrap> " << this->name << "needs to be repaired before trying to attack." << std::endl;
	else if (this->energyPoints == 0)
		std::cout << "<ScavTrap> " << this->name << "needs an energy boost before trying to attack." << std::endl;
}