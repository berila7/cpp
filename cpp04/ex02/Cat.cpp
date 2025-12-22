#include "Cat.hpp"
#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

Cat::Cat( void ) :	Animal("Cat") 
{
	_catBrain = new Brain();
	std::cout << "cat created" << std::endl;
}

Cat::Cat( Cat const &other ) : Animal(other)
{
	_catBrain = new Brain(*other._catBrain);
	std::cout << "Cat copied" << std::endl;
}

Cat::~Cat(void)
{
	delete _catBrain;
	std::cout << "Cat destructed" << std::endl;
}

Cat &	Cat::operator=( Cat const &other )
{
	if (this != &other)
	{
		Animal::operator=(other);
		delete _catBrain;
		_catBrain = new Brain(*other._catBrain);
	}
	return (*this);
}

void	Cat::makeSound( void ) const
{
	std::cout << "Cat sound" << std::endl;
}