#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain*	_dogBrain;

public:
	Dog( void );
	Dog( Dog const &other );
	Dog &operator=( Dog const &other );
	virtual ~Dog( void );

	virtual void	makeSound( void ) const;
};

#endif