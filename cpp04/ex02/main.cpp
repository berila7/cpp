#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    const Animal* animals[4];
    for (int i = 0; i < 2; i++)
        animals[i] = new Dog();
    
    for (int i = 2; i < 4; i++)
        animals[i] = new Cat();

    for (int i = 0; i < 4; i++)
        animals[i]->makeSound();
    
    for (int i = 0; i < 4; i++)
        delete animals[i];
    Dog basic;
    Dog tmp = basic;
	Dog dog1;
    Dog dog2;
    dog2 = dog1;
    return 0;
}