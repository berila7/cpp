#include <iostream>
#include "Harl.hpp"

int main( int ac, char *av[] )
{
    if (ac != 2)
    {
        std::cout << "Invalid args" << std::endl;
        return (1);
    }
    Harl first;
    first.complain(av[1]);

    return (0);
}