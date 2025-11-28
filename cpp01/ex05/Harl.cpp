#include <iostream>
#include "Harl.hpp"

Harl::Harl(){}
Harl::~Harl(){}

void    Harl::debug( void )
{
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "message" << std::endl;
}

void    Harl::info( void )
{
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "message" << std::endl;
}

void    Harl::warning( void )
{
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "message" << std::endl;
}

void    Harl::error( void )
{
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "message" << std::endl;
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
        else if (i == 3)
            std::cout << "Invalid level" << std::endl;
    }
    
}