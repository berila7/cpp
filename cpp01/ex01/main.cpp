#include "Zombie.h"
#include "Zombie.hpp"
#include <iostream>

int main( void )
{
	Zombie* myHorde = zombieHorde(5, "mohammed");

	for (int i = 0; i < 5; i++)
	{
		myHorde[i].announce();
	}
	delete[] myHorde;
}