#include "Dog.hpp"
#include "Animal.hpp"
#include <iostream>

Dog::Dog( void ) :	Animal("Dog")
{
	std::cout << "dog created" << std::endl;
}

Dog::Dog( Dog const &other ) :	Animal(other)
{
	std::cout << "dog copied" << std::endl;
}

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