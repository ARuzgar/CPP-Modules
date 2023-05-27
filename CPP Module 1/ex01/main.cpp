#include "Zombie.hpp"

int main(int ac, char **av)
{
	if (ac != 3){
		std::cout << "Insufficent Arguments. Please follow the template : ./zombieHorde [NumberOfZombies] [NameOfZombies]" << std::endl;
	}
	else if (atoi(av[1]) < 1)
		std::cout << "There Should Be Atleast 1 Zombie" << std:: endl;
	else if (ac == 3){
		int z = atoi(av[1]);
		Zombie *zombies = zombieHorde(z, av[2]);
		for (int i = 0; i < z; i++)
			zombies[i].announce();
		delete[] zombies;
		exit (0);
	}
	exit (1);
}