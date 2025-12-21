#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	Animal* animals[100];
	for (size_t i = 0; i <= 100; i++)
	{
		if (i <= 50)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}
	return 0;
}