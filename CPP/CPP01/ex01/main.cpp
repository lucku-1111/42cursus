#include "Zombie.hpp"

int	main(void)
{
	int	num = 10;
	Zombie	*zombies = zombieHorde(num, "cloneZombie");

	for (int i = 0; i < num; i++)
		zombies[i].announce();
	delete[] zombies;
	return (0);
}
