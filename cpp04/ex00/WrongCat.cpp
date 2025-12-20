#include "WrongCat.hpp"
#include "WrongAnimal.hpp"
#include <iostream>

WrongCat::WrongCat( void ) :	WrongAnimal("WrongCat") {}

WrongCat::WrongCat( std::string value ) :	WrongAnimal(value) {}

WrongCat::WrongCat( WrongCat const &other ) : WrongAnimal(other) {}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat destructed" << std::endl;
}

WrongCat &	WrongCat::operator=( WrongCat const &other )
{
	if (this != &other)
		WrongAnimal::operator=(other);
	return (*this);
}
