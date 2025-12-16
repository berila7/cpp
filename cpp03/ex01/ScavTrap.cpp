#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap( void ) 
	:	ClapTrap("default", 100, 50, 20)
{
	std::cout << "ScavTrap ";
	std::cout << _name;
	std::cout << " reporting for duty!";
	std::cout << std::endl;
}

ScavTrap::ScavTrap( std::string value )
	:	ClapTrap(value, 100, 50, 20)
{
	std::cout << "ScavTrap ";
	std::cout << _name;
	std::cout << " has been assembled!";
	std::cout << std::endl;
}

ScavTrap::ScavTrap( ScavTrap const &other )
	:	ClapTrap(other)
{
	std::cout << "A copy of ScavTrap ";
	std::cout << _name;
	std::cout << " emerges";
	std::cout << std::endl;
}

ScavTrap&	ScavTrap::operator=( ScavTrap const &rhs )
{
	if (this != &rhs)
		ClapTrap::operator=(rhs);
	return (*this);
}

ScavTrap::~ScavTrap( void )
{
	std::cout << "ScavTrap ";
	std::cout << _name;
	std::cout << " shuts down!";
	std::cout << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (_hitPoint <= 0 || _energyPoint <= 0)
	{
		std::cout << "ScavTrap Can't attack" << std::endl;
		return ;
	}
	_energyPoint--;
	std::cout << "ScavTrap ";
	std::cout << _name << " attacks " << target;
	std::cout << ", causing " << _attackDamage << " points of damage!";
	std::cout << std::endl;
}

void	ScavTrap::guardGate( void )
{
	std::cout << "ScavTrap is now in Gate keeper mode." << std::endl;
}