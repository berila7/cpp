#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	const Animal animals[100];
	for (size_t i = 0; i <= 100; i++)
	{
		if (i < 50)
			animals[i] = Dog();
		else
			animals[i] = Cat();
	}
	return 0;
}