#include <iostream>
#include "Zombie.hpp"

int main( void )
{
	Zombie *myZombie = newZombie("real zombie");
	myZombie->announce();

	randomChump("Chump zombie");
	
	delete myZombie;

}