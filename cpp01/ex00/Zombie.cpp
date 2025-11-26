#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie( std::string value ) : name(value) {}

void	Zombie::announce( void )
{
	std::cout << name;
	std::cout << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie()
{
	std::cout << name << ": destroyed" << std::endl;
}