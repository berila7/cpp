#include "Fixed.hpp"
#include <cmath>
#include <iostream>

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

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

// Assignment operator:
Fixed& Fixed::operator=(const Fixed& src )
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this !=  &src)
	{
		_value = src._value;
	}
	return (*this);
}

// Arithmetic operator:
Fixed	Fixed::operator+(const Fixed& other ) const
{
	return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed	Fixed::operator-(const Fixed& other ) const
{
	return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed	Fixed::operator*(const Fixed& other ) const
{
	return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed	Fixed::operator/(const Fixed& other ) const
{
	return (Fixed(this->toFloat() / other.toFloat()));
}

// Comparison operators:
bool	Fixed::operator>( const Fixed& other ) const
{
	return (this->_value > other._value);
}

bool	Fixed::operator<( const Fixed& other ) const
{
	return (this->_value < other._value);
}

bool	Fixed::operator>=( const Fixed& other ) const
{
	return (this->_value >= other._value);
}

bool	Fixed::operator<=( const Fixed& other ) const
{
	return (this->_value <= other._value);
}

bool	Fixed::operator==( const Fixed& other ) const
{
	return (this->_value == other._value);
}

bool	Fixed::operator!=( const Fixed& other ) const
{
	return (this->_value != other._value);
}

// Ancrement/Decrement operators:
Fixed&	Fixed::operator++( void )
{
	this->_value += 1;
	return (*this);
}

Fixed&	Fixed::operator--( void )
{
	this->_value -= 1;
	return (*this);
}

Fixed	Fixed::operator++( int )
{
	Fixed copy(*this);
	this->_value += 1;
	return (copy);
}

Fixed	Fixed::operator--( int )
{
	Fixed copy(*this);
	this->_value -= 1;
	return (copy);
}

//Min/Max functions
Fixed&	Fixed::min(Fixed& src, Fixed& other)
{
	if (src < other)
		return (src);
	return (other);
}

const Fixed&	Fixed::min(const Fixed& src, const Fixed& other)
{
	if (src < other)
		return (src);
	return (other);
}

Fixed&	Fixed::max(Fixed& src, Fixed& other)
{
	if (src > other)
		return (src);
	return (other);
}

const Fixed&	Fixed::max(const Fixed& src, const Fixed& other)
{
	if (src > other)
		return (src);
	return (other);
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