#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap target("Daddy Melih");
	ClapTrap bademAdem("bademAdem");
	ClapTrap ademArdaBerkeNargulBebek("ademArdaBerkeNargulBebek");
	ClapTrap *clapTrapHorde = new ClapTrap[3];
	for (int i = 0; i < 3; i++)
	{
		clapTrapHorde[i].attack(target.getName());
		target.takeDamage(clapTrapHorde[i].getAttackDamage());
	}
	ademArdaBerkeNargulBebek.attack("bademAdem");
	bademAdem.takeDamage(3);
	bademAdem.takeDamage(10);
	bademAdem.takeDamage(10);
	bademAdem.beRepaired(3);
	bademAdem.beRepaired(7);
	ademArdaBerkeNargulBebek = bademAdem;
	target.beRepaired(3);
	delete [] clapTrapHorde;
	return (0);
}