#include "Fixed.hpp"
#include "Point.hpp"

Fixed	pointCheck(Point const start, Point const end, Point const point)
{
	Fixed	value;
	value = (end.getX() - start.getX()) * (point.getY() - start.getY())
	  - (end.getY() - start.getY()) * (point.getX() - start.getX());
	return (value);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed	val1 = pointCheck(a, b, point);
	Fixed	val2 = pointCheck(b, c, point);
	Fixed	val3 = pointCheck(c, a, point);
	if (val1 > 0 && val2 > 0 && val3 > 0)
		return (true);
	if (val1 < 0 && val2 < 0 && val3 < 0)
		return (true);
	return (false);
} 