#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include <string>

class Cat : public Animal
{
private:

public:
	Cat( void );
	Cat( Cat const &other );
	Cat &operator=( Cat const &other );
	virtual ~Cat(void);

	virtual void	makeSound( void ) const;
};

#endif