#include "Animal.hpp"
#include <iostream>

Animal::Animal( void ) :	_type("animal") {}

Animal::Animal( std::string value ) :	_type(value) {}

Animal::Animal( Animal const &other ) :	_type(other._type) {}

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
