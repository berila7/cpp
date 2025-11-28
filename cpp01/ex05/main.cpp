#include <iostream>
#include "Harl.hpp"

int main( void )
{
    Harl first;
    first.complain("DEBUG");
    std::cout << "-----------" << std::endl;
    first.complain("INFO");

    std::cout << "-----------" << std::endl;
    first.complain("WARNING");

    std::cout << "-----------" << std::endl;
    first.complain("ERROR");

    std::cout << "-----------" << std::endl;
    first.complain("WALO");

    return (0);
}