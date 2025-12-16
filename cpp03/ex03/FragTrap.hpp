#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <string>

class FragTrap : public virtual ClapTrap
{
public:
	FragTrap( void );
	FragTrap( std::string value );
	FragTrap( FragTrap const &other );
	FragTrap &operator=( FragTrap const &other );
	~FragTrap( void );

	void highFivesGuys( void );

};

#endif