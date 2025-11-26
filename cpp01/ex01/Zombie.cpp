#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie() : name("Foo") {}

void	Zombie::announce( void )
{
	std::cout << name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string value)
{
	name = value;
}

Zombie::~Zombie()
{
	std::cout << name << ": destroyed" << std::endl;
}