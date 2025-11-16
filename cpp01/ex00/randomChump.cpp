#include <iostream>
#include "Zombie.hpp"

void randomChump( std::string name )
{
	Zombie	chump;
	chump.setZombieName(name);
	chump.announce();
}