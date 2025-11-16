#include <iostream>
#include "Zombie.hpp"

void	Zombie::setZombieName(std::string zombieName)
{
	name = zombieName;
}

Zombie::Zombie()
{
	
}

std::string	Zombie::getZombieName( void )
{
	return (name);
}

void	Zombie::announce( void )
{
	std::cout << name;
	std::cout << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "The zombie "; 
	std::cout << name << " is destroyed" << std::endl;
}