#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>

class Animal
{
protected:
	std::string _type;
public:
	Animal( void );
	Animal( std::string value );
	Animal( Animal const &other );
	Animal &operator=( Animal const &other );
	virtual ~Animal( void );

	const std::string&	getType( void ) const;

	virtual void	makeSound( void ) const;
};

#endif