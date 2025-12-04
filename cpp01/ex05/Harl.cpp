#include <iostream>
#include "Harl.hpp"

Harl::Harl(){}
Harl::~Harl(){}

void    Harl::debug( void )
{
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "message 1" << std::endl;
}

void    Harl::info( void )
{
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "message 2" << std::endl;
}

void    Harl::warning( void )
{
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "message 3" << std::endl;
}

void    Harl::error( void )
{
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "message 4" << std::endl;
}

void    Harl::complain( std::string level )
{
    void (Harl::*ptr[4])(void) = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
    std::string levels[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };
    
    for (size_t i = 0; i < 4; i++)
    {
        if (level == levels[i])
        {
            (this->*ptr[i])();
            break ;
        }
    }
}