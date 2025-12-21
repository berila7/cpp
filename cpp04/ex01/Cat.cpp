#include "Cat.hpp"
#include "Animal.hpp"
#include <iostream>

Cat::Cat( void ) :	Animal("Cat") 
{
	_catBrain = new Brain();
}

Cat::Cat( Cat const &other ) : Animal(other) {}

Cat::~Cat(void)
{
	delete _catBrain;
	std::cout << "Animal sound" << std::endl;
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