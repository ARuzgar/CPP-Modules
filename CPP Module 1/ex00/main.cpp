#include "Zombie.hpp"

int main(void)
{
	Zombie *zombie = newZombie("Zombie Ozcan Tekin");
	Zombie *zombie2 = new Zombie("Zombie Deniz Seki");
	zombie->announce();
	zombie2->announce();
	delete zombie;
	delete zombie2;
	randomChump("Random Encounter");
	return (0);
}