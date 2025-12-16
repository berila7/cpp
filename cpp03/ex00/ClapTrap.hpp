#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

class ClapTrap
{
private:
	std::string 			_name;
	unsigned int			_hitPoint;
	unsigned int			_energyPoint;
	unsigned int			_attackDamage;
public:

	ClapTrap();
	ClapTrap(const ClapTrap& other);
	ClapTrap(std::string name);
	ClapTrap&	operator=(const ClapTrap& other);
	~ClapTrap();

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif