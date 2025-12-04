#include "Zombie.hpp"
#include <iostream>

int main( void )
{
	Zombie* myHorde = zombieHorde(3, "hmd");

	for (int i = 0; i < 3; i++)
	{
		myHorde[i].announce();
	}
	delete[] myHorde;
}