#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main()
{
    std::srand(std::time(NULL));

    std::cout << "\n===== SHRUBBERY TEST =====\n";
    {
        Bureaucrat boss("Boss", 1);
        ShrubberyCreationForm form("home");

        boss.executeForm(form); // not signed

        boss.signForm(form);
        boss.executeForm(form);
    }

    std::cout << "\n===== ROBOTOMY TEST =====\n";
    {
        Bureaucrat boss("Boss", 1);
        RobotomyRequestForm form("Bender");

        boss.signForm(form);

        boss.executeForm(form);
    }

    std::cout << "\n===== PRESIDENTIAL TEST =====\n";
    {
        Bureaucrat president("President", 1);
        PresidentialPardonForm form("Marvin");

        president.signForm(form);
        president.executeForm(form);
    }

    std::cout << "\n===== LOW GRADE TEST =====\n";
    {
        Bureaucrat low("Low", 150);
        ShrubberyCreationForm form("garden");

        low.signForm(form);
        low.executeForm(form);
    }

    return 0;
}