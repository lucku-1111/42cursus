#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon)
{
}

HumanA::~HumanA(void)
{
}

void	HumanA::attack(void)
{
	std::cout << this->name << " attack with " << this->weapon.getType() << std::endl;
}
