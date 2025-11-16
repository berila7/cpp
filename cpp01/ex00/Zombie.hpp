#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{
private:
	std::string	name;
public:
	void announce( void );
	void setZombieName( std::string name );

	std::string getZombieName( void );
	Zombie();
	~Zombie();
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif