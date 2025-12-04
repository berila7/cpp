#include <iostream>
#include "Zombie.hpp"

int main( void )
{
	Zombie *myZombie = newZombie("hmd");
	myZombie->announce();

	randomChump("rayan");
	
	delete myZombie;
}
