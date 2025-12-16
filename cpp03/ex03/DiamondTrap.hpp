#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <string>

class DiamondTrap : public ScavTrap, public FragTrap
{
private:
	std::string _name;
public:
	DiamondTrap( void );
	DiamondTrap( std::string value );
	DiamondTrap( DiamondTrap const &other );
	DiamondTrap &operator=( DiamondTrap const &other );
	~DiamondTrap( void );

	void	attack( const std::string& target );
	void	whoAmI( void );

};

#endif