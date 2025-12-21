#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <string>

class WrongAnimal
{
private:
	std::string type;
public:
	WrongAnimal( void );
	WrongAnimal ( std::string value );
	WrongAnimal( WrongAnimal const &other );
	WrongAnimal &operator=( WrongAnimal const &other );
	virtual ~WrongAnimal( void );

	void	makeSound( void ) const;

};

#endif