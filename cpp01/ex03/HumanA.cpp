#include <iostream>
#include "Weapon.hpp"
#include "HumanA.hpp"

void	HumanA::attack()
{
	std::cout << name;
	std::cout << " attacks with their ";
	std::cout << weapon.getType() << std::endl;
}

HumanA::HumanA(std::string value, Weapon& weaponValue) 
	: name(value), weapon(weaponValue) {}

HumanA::~HumanA()
{

}