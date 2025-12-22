#include "Dog.hpp"
#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

Dog::Dog( void ) :	Animal("Dog")
{
	_dogBrain = new Brain();
	std::cout << "dog created" << std::endl;
}

Dog::Dog( Dog const &other ) :	Animal(other)
{
	_dogBrain = new Brain(*other._dogBrain);
	std::cout << "dog copied" << std::endl;
}

Dog::~Dog( void )
{
	delete _dogBrain;
	std::cout << "Dog destructed" << std::endl;
}

Dog&	Dog::operator=( Dog const &other )
{
	if (this != &other)
	{
		Animal::operator=(other);
		delete _dogBrain;
		_dogBrain = new Brain(*other._dogBrain);
		
	}
	return (*this);
}

void	Dog::makeSound( void ) const
{
	std::cout << "Dog sound" << std::endl;
}