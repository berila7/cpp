#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include <string>

class Cat : public Animal
{
private:

public:
	Cat( void );
	Cat( std::string value );
	Cat( Cat const &other );
	Cat &operator=( Cat const &other );
	~Cat(void);

	void	makeSound( void ) const;
};

#endif