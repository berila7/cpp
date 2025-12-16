#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <filesystem>
#include <iostream>

DiamondTrap::DiamondTrap( void )
	:	ClapTrap("android"),
		ScavTrap("android"),
		FragTrap("android")
{
	_hitPoint = 100;
	_energyPoint = 50;
	_attackDamage = 30;
	std::cout << "DiamondTrap ";
	std::cout << _name;
	std::cout << " is born ";
	std::cout << std::endl;
}

DiamondTrap::DiamondTrap( std::string value )
	:	ClapTrap(value + "_clap_name"),
		ScavTrap(value),
		FragTrap(value)
{
	_name = value;
	_hitPoint = 100;
	_energyPoint = 50;
	_attackDamage = 30;
	std::cout << "DiamondTrap ";
	std::cout << _name;
	std::cout << " is born 2 !";
	std::cout << std::endl;
}

DiamondTrap::DiamondTrap( DiamondTrap const &other )
	:	ClapTrap(other),
		ScavTrap(other),
		FragTrap(other)
{
	_name = other._name;
	std::cout << "copy of DiamondTrap ";
	std::cout << _name;
	std::cout << " ready";
	std::cout << std::endl;
}

DiamondTrap::~DiamondTrap( void )
{
	std::cout << "DiamondTrap ";
	std::cout << _name << " is dead";
	std::cout << std::endl;
}

DiamondTrap &	DiamondTrap::operator=( DiamondTrap const &other )
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
		_name = other._name;
	}
	return (*this);
}

void	DiamondTrap::attack( const std::string& target )
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI( void )
{
	std::cout << "ClapTrap name: " << ClapTrap::_name << std::endl;
	std::cout << "DiamondTrap name: " << _name << std::endl;
}