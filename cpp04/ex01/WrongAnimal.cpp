#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal( void ) :	type("animal")
{
	std::cout << "wrong animal created" << std::endl;
}

WrongAnimal::WrongAnimal( std::string value ) :	type(value)
{
	std::cout << "wrong animal created with value" << std::endl;
}

WrongAnimal::WrongAnimal( WrongAnimal const &other ) :	type(other.type)
{
	std::cout << "wrong animal copied" << std::endl;
}

WrongAnimal::~WrongAnimal( void )
{
	std::cout << "WrongAnimal destructed" << std::endl;
}

WrongAnimal&	WrongAnimal::operator=( WrongAnimal const &other )
{
	if (this != &other)
		type = other.type;
	return (*this);
}

void	WrongAnimal::makeSound( void ) const
{
	std::cout << "WrongAnimal sound" << std::endl;
}