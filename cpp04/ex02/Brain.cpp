#include "Brain.hpp"
#include <iostream>

Brain::Brain(void)
{
    for (size_t i = 0; i < 100; i++)
        _ideas[i] = "default idea";
}

Brain::Brain(Brain const &other)
{
    for (size_t i = 0; i < 100; i++)
        _ideas[i] = other._ideas[i];
}

Brain& Brain::operator=(Brain const &other)
{
    if (this == &other)
        return (*this);
    for (size_t i = 0; i < 100; i++)
        _ideas[i] = other._ideas[i];
    return (*this);
}
Brain::~Brain(void)
{
    std::cout << "Brain Destructed" << std::endl;
}