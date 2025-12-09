#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	_value = 0;
}

Fixed::Fixed( int const num )
{
	std::cout << "Int constructor called" << std::endl;
	_value = num * (1 << _fractionalBits);
}

Fixed::Fixed( float const num )
{
	std::cout << "Float constructor called" << std::endl;
	_value = roundf(num * (1 << _fractionalBits));
}

Fixed::Fixed( const Fixed& src )
{
	std::cout << "Copy constructor called" << std::endl;
	_value = src._value;
}

// Assignment operator:
Fixed&	Fixed::operator=(const Fixed& other )
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this !=  &other)
	{
		_value = other._value;
	}
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

float	Fixed::toFloat( void ) const
{
	return ((float)_value / (1 << _fractionalBits));
}

int		Fixed::toInt( void ) const
{
	return (_value / (1 << _fractionalBits));
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

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return (os);
}