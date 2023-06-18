#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap *clapTrapHorde = new ClapTrap[3];
	ClapTrap target("Daddy Melih");
	for (int i = 0; i < 3; i++)
	{
		clapTrapHorde[i].attack(target.getName());
		target.takeDamage(clapTrapHorde[i].getAttackDamage());
	}
	delete [] clapTrapHorde;
	target.beRepaired(3);
	return (0);
}