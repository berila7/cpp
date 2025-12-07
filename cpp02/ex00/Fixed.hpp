#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
private:
	int					_value;
	static int const	_fractionalBits = 8;
public:
	Fixed();
	Fixed( const Fixed& obj );
	Fixed&	operator=( const Fixed& src);
	~Fixed();

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
};

#endif