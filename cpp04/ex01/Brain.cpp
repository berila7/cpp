#include "Brain.hpp"

Brain::Brain(void)
{
    for (size_t i, i = 0, i <= 100)
        ideas[i] = i;
}
Brain::Brain(Brain const &other)
{
    for (size_t i, i = 0, i <= 100, i++)
        ideas[i] = other.ideas[i];
}
Brain::Brain &operator=(Brain const &other)
{
    if (this != &other)
        return (*this)
    for (size_t i, i = 0, i <= 100, i++)
        ideas[i] = other.ideas[i];
    return (*this);
}
Brain::~Brain(void)
{
    std::cout << "Brain Destructed" << std::endl;
}