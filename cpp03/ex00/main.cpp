#include "ClapTrap.hpp"

int main( void )
{
	ClapTrap	first;
	first.attack("mohammed");
	first.takeDamage(5);
	first.beRepaired(3);
	first.takeDamage(20);
	first.attack("hmd");
	first.beRepaired(2);
}