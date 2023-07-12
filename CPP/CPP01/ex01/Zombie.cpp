#include "Zombie.hpp"

Zombie::Zombie(void)
{
	this->name = "default";
	std::cout << "Zombie(" << this->name << ") constructor called." << std::endl;
}

Zombie::Zombie(std::string name)
{
	this->name = name;
	std::cout << "Zombie(" << this->name << ") constructor called." << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << "Zombie(" << this->name << ") destructor called." << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string name)
{
	this->name = name;
}
