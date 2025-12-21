#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <string>

class Dog : public Animal
{
private:
	Brain*	_dogBrain;

public:
	Dog( void );
	Dog( Dog const &other );
	Dog &operator=( Dog const &other );
	~Dog( void );

	void	makeSound( void ) const;
};

#endif