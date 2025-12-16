#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <string>

class FragTrap : public ClapTrap
{
public:
	FragTrap( void );
	FragTrap( std::string value );
	FragTrap( FragTrap const &instance );
	FragTrap &operator=( FragTrap const &rhs );
	~FragTrap( void );

	void highFivesGuys( void );

};

#endif