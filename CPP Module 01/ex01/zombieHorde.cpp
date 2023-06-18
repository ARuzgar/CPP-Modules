#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name){
	Zombie *zombieHorde = new Zombie[N];
	for (int i = N; i >= 0; i--)
		zombieHorde[i].setZombieName(name);
	return (zombieHorde);
}