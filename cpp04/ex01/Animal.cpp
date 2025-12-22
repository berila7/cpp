#include "Animal.hpp"
#include <iostream>

Animal::Animal( void ) :	_type("animal")
{
	std::cout << "Animal construced" << std::endl;
}

Animal::Animal( std::string value ) :	_type(value)
{
	std::cout << "Animal construced with value" << std::endl;
}

Animal::Animal( Animal const &other ) :	_type(other._type)
{
	std::cout << "Animal copied" << std::endl;
}

Animal::~Animal( void )
{
	std::cout << "Animal destructed" << std::endl;
}

Animal&	Animal::operator=( Animal const &other )
{
	if (this != &other)
		_type = other._type;
	return (*this);
}

const std::string&	Animal::getType( void ) const
{
	return (_type);
}

void	Animal::makeSound( void ) const
{
	std::cout << "Animal sound" << std::endl;
}