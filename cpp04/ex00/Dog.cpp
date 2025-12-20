#include "Dog.hpp"
#include "Animal.hpp"
#include <iostream>

Dog::Dog( void ) :	Animal("Dog") {}

Dog::Dog( std::string value ) :	Animal(value) {}

Dog::Dog( Dog const &other ) :	Animal(other) {}

Dog::~Dog( void )
{
	std::cout << "Dog destructed" << std::endl;
}

Dog&	Dog::operator=( Dog const &other )
{
	if (this != &other)
		Animal::operator=(other);
	return (*this);
}

void	Dog::makeSound( void ) const
{
	std::cout << "Dog sound" << std::endl;
}