#include <iostream>
#include "Weapon.hpp"

const std::string&	Weapon::getType() const
{
	return (type);
}

void	Weapon::setType(std::string value)
{
	type = value;
}

Weapon::Weapon(std::string value) : type(value) {}

Weapon::~Weapon()
{
	
}