#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int					_value;
	static int const	_fractionalBits = 8;
public:
	Fixed();
	Fixed( int const num );
	Fixed( float const num );
	Fixed( const Fixed& obj );
	~Fixed();
	
	Fixed&	operator=( const Fixed& src);
	// Arithmetic operators:
	Fixed	operator+( const Fixed& other );
	Fixed	operator-( const Fixed& other );
	Fixed	operator*( const Fixed& other );
	Fixed	operator/( const Fixed& other );
	// Comparison operators:
	bool	operator>( const Fixed& other ) const;
	bool	operator<( const Fixed& other ) const;
	bool	operator>=( const Fixed& other ) const;
	bool	operator<=( const Fixed& other ) const;
	bool	operator==( const Fixed& other ) const;
	bool	operator!=( const Fixed& other ) const;
	// Ancrement/Decrement operators:
	Fixed&	operator++( void );
	Fixed	operator++( int );
	Fixed&	operator--( void );
	Fixed	operator--( int );
	//Min/Max functions
	static Fixed&	min(Fixed& src, Fixed& other);
	static const Fixed&	min(const Fixed& src, const Fixed& other);
	static Fixed&	max(Fixed& src, Fixed& other);
	static const Fixed&	max(const Fixed& src, const Fixed& other);

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	float	toFloat( void ) const;
	int		toInt( void ) const;

};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif