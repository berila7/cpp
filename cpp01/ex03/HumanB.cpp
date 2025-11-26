#include <iostream>
#include "Weapon.hpp"
#include "HumanB.hpp"

void	HumanB::attack()
{
	if (weapon)
	{
		std::cout << name;
		std::cout << " attacks with their ";
		std::cout << weapon->getType() << std::endl;
	}
	else
		std::cout << name << " has no weapon yet" << std::endl;
}

void	HumanB::setWeapon(Weapon& value)
{
	weapon = &value;
}

HumanB::HumanB(std::string value) : name(value), weapon(NULL) {}

HumanB::~HumanB()
{

}