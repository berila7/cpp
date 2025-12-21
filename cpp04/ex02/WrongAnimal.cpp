#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal( void ) :	type("animal") {}

WrongAnimal::WrongAnimal( std::string value ) :	type(value) {}

WrongAnimal::WrongAnimal( WrongAnimal const &other ) :	type(other.type) {}

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