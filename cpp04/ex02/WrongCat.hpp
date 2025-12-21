#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"
#include <string>

class WrongCat : public WrongAnimal
{
public:
	WrongCat( void );
	WrongCat( WrongCat const &instance );
	WrongCat &operator=( WrongCat const &rhs );
	virtual ~WrongCat( void );

	void	makeSound( void );
};

#endif