#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
protected :
	std::string 			_name;
	unsigned int			_hitPoint;
	unsigned int			_energyPoint;
	unsigned int			_attackDamage;
public :

	ClapTrap( void );
	ClapTrap( const ClapTrap& other );
	ClapTrap( std::string name );
	ClapTrap( std::string name, unsigned int hitP, unsigned int energyP, unsigned int attackD);
	ClapTrap&	operator=( const ClapTrap& other );
	~ClapTrap();

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif