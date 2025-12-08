#include "Point.hpp"
#include "Fixed.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(const float num1, const float num2)
	: x(num1), y(num2) {}

Point::Point(const Point& src) : x(src.x), y(src.y) {}

Point&	Point::operator=(const Point& src)
{
	(void)src;
	return (*this);
}

Point::~Point() {}

const	Fixed&	Point::getX( void ) const
{
	return (x);
}

const	Fixed&	Point::getY( void ) const
{
	return (y);
}