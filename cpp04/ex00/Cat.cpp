#include "Cat.hpp"
#include "Animal.hpp"
#include <iostream>

Cat::Cat( void ) :	Animal("Cat") {}

Cat::Cat( Cat const &other ) : Animal(other) {}

Cat::~Cat(void)
{
	std::cout << "Cat destructed" << std::endl;
}

Cat &	Cat::operator=( Cat const &other )
{
	if (this != &other)
		Animal::operator=(other);
	return (*this);
}

void	Cat::makeSound( void ) const
{
	std::cout << "Cat sound" << std::endl;
}