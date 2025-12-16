#include "FragTrap.hpp"
#include "ClapTrap.hpp"

FragTrap::FragTrap( void ) 
	:	ClapTrap("Fault", 100, 100, 30)
{
	std::cout << "FragTrap ";
	std::cout << _name;
	std::cout << " is ready ";
	std::cout << std::endl;
}

FragTrap::FragTrap( std::string value )
	:	ClapTrap(value, 100, 100, 30)
{
	std::cout << "FragTrap ";
	std::cout << _name;
	std::cout << " is ready 2 !";
	std::cout << std::endl;
}

FragTrap::FragTrap( FragTrap const &other )
	:	ClapTrap(other)
{
	std::cout << "copy of FragTrap ";
	std::cout << _name;
	std::cout << " ready";
	std::cout << std::endl;
}

FragTrap&	FragTrap::operator=( FragTrap const &rhs )
{
	if (this != &rhs)
		ClapTrap::operator=(rhs);
	return (*this);
}

FragTrap::~FragTrap( void )
{
	std::cout << "FragTrap ";
	std::cout << _name;
	std::cout << " dies";
	std::cout << std::endl;
}

void FragTrap::highFivesGuys( void )
{
	std::cout << "FragTrap requests positive high-fives! ✋" << std::endl;
}