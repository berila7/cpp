#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

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
	
	Fixed&	operator=( const Fixed& other );


	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	float	toFloat( void ) const;
	int		toInt( void ) const;

};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif