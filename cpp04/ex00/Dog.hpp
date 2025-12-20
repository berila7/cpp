#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include <string>

class Dog : public Animal
{
private:

public:
	Dog( void );
	Dog( std::string value );
	Dog( Dog const &other );
	Dog &operator=( Dog const &other );
	~Dog( void );

	void	makeSound( void ) const;
};

#endif