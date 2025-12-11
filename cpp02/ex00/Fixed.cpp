#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	_value = 0;
}

Fixed::Fixed( const Fixed& src )
{
	std::cout << "Copy constructor called" << std::endl;
	_value = src._value;
}

Fixed& Fixed::operator=(const Fixed& src )
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this !=  &src)
	{
		_value = src._value;
	}
	return (*this);
} 

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_value);
}

void Fixed::setRawBits( int const raw )
{
	_value = raw;
}