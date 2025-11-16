#include <iostream>
#include "Zombie.hpp"

void	Zombie::announce( void )
{
	std::cout << name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setZombieName(std::string value)
{
	name = value;
}

Zombie::Zombie()
{

}

Zombie::~Zombie()
{
	std::cout << "The zombie "; 
	std::cout << name << " is destroyed" << std::endl;
}