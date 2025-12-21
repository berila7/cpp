#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <string>

class Cat : public Animal
{
private:
	Brain*	_catBrain;

public:
	Cat( void );
	Cat( Cat const &other );
	Cat &operator=( Cat const &other );
	~Cat(void);

	void	makeSound( void ) const;
};

#endif