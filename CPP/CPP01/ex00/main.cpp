#include "Zombie.hpp"

int	main(void)
{
	std::cout << "----- defaultZombie -----" << std::endl;
	Zombie	defaultZombie;

	defaultZombie.announce();

	std::cout << "----- namedZombie -----" << std::endl;;
	Zombie	namedZombie("namedZombie");

	namedZombie.announce();

	std::cout << "----- newZombie -----" << std::endl;
	Zombie	*nZombie = newZombie("newZombie");

	nZombie->announce();

	std::cout << "----- randomChump -----" << std::endl;
	randomChump("randomChump");

	std::cout << "----- delete newZombie -----" << std::endl;
	delete nZombie;

	std::cout << "----- return -----" << std::endl;
	return (0);
}
