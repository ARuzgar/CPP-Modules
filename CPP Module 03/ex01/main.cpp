#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void){
	ClapTrap target("Melih");
	target.beRepaired(3);
	ScavTrap s;
	s.attack("Melih");
	s.beRepaired(10);
	s.guardGate();
	s.takeDamage(15);
	return (0);
}