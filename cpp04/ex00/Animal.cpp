#include "Animal.hpp"
#include <iostream>

Animal::Animal( void ) :	type("animal") {}

Animal::Animal( std::string value ) :	type(value) {}

Animal::Animal( Animal const &other ) :	type(other.type) {}

Animal::~Animal( void )
{
	std::cout << "Animal destructed" << std::endl;
}

Animal&	Animal::operator=( Animal const &other )
{
	if (this != &other)
		type = other.type;
	return (*this);
}

const std::string&	Animal::getType( void ) const
{
	return (type);
}

void	Animal::makeSound( void ) const
{
	std::cout << "Animal sound" << std::endl;
}