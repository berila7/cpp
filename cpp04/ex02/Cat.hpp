#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
	Brain*	_catBrain;

public:
	Cat( void );
	Cat( Cat const &other );
	Cat &operator=( Cat const &other );
	virtual ~Cat(void);

	virtual void	makeSound( void ) const;
};

#endif