#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap( void )
	:	_name("default"),
		_hitPoint(10),
		_energyPoint(10),
		_attackDamage(0)
{
	std::cout << "ClapTrap ";
	std::cout << _name << " created";
	std::cout << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
	:	_name(other._name),
		_hitPoint(other._hitPoint),
		_energyPoint(other._energyPoint),
		_attackDamage(other._attackDamage)
{
	std::cout << "ClapTrap ";
	std::cout << _name << " cloned";
	std::cout << std::endl;
}

ClapTrap::ClapTrap(std::string value) 
	:	_name(value),
		_hitPoint(10),
		_energyPoint(10),
		_attackDamage(0)
{
	std::cout << "ClapTrap ";
	std::cout << _name << " created";
	std::cout << std::endl;
}

ClapTrap::ClapTrap( std::string name, unsigned int hitP, unsigned int energyP, unsigned int attackD)
	:	_name(name),
		_hitPoint(hitP),
		_energyPoint(energyP),
		_attackDamage(attackD)
{
	std::cout << "ClapTrap ";
	std::cout << _name << " created";
	std::cout << std::endl;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& other)
{
	if (this != &other)
	{
		_name = other._name;
		_hitPoint = other._hitPoint;
		_energyPoint = other._energyPoint;
		_attackDamage = other._attackDamage;
	}
	return (*this);
}

ClapTrap::~ClapTrap( void )
{
	std::cout << "ClapTrap ";
	std::cout << _name << " destroyed";
	std::cout << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (_hitPoint <= 0 || _energyPoint <= 0)
	{
		std::cout << "ClapTrap Can't attack" << std::endl;
		return ;
	}
	_energyPoint--;
	std::cout << "ClapTrap ";
	std::cout << _name << " attacks " << target;
	std::cout << ", causing " << _attackDamage << " points of damage!";
	std::cout << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap ";
	std::cout << _name << " was attacked";
	std::cout << std::endl;
	if (amount > _hitPoint)
	{
		_hitPoint = 0;
		return ;
	}
	_hitPoint -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_energyPoint <= 0 || _hitPoint <= 0)
	{
		std::cout << "ClapTrap Can't repair himself" << std::endl;
		return ;
	}
	_energyPoint--;
	_hitPoint += amount;
	std::cout << "ClapTrap ";
	std::cout << _name << " repaired himself";
	std::cout << std::endl;
}
