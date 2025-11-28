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
    int i = 0;
    std::string levels[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };

    while (i < 4 && levels[i] != level)
        i++;
    
    switch (i)
    {
    case 0:
        this->debug();
        // Fallthrough...
    case 1:
        this->info();
        // Fallthrough...
    case 2:
        this->warning();
        // Fallthrough...
    case 3:
        this->error();
        break;
    default:
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
}