#include "Cat.hpp"
#include "Animal.hpp"
#include <iostream>

Cat::Cat( void ) :	Animal("Cat")
{
	std::cout << "cat created" << std::endl;
}

Cat::Cat( Cat const &other ) : Animal(other)
{
	std::cout << "cat copied" << std::endl;
}

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