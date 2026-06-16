#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main()
{
    std::srand(std::time(NULL));

    Intern intern;

    std::cout << "\n===== SHRUBBERY TEST =====\n";
    AForm* shrubbery = intern.makeForm("shrubbery creation", "home");

    if (shrubbery)
    {
        Bureaucrat boss("Boss", 1);

        boss.executeForm(*shrubbery);
        boss.signForm(*shrubbery);
        boss.executeForm(*shrubbery);
 
        delete shrubbery;
    }

    std::cout << "\n===== ROBOTOMY TEST =====\n";
    AForm* robotomy = intern.makeForm("robotomy request", "Bender");

    if (robotomy)
    {
        Bureaucrat boss("Boss", 1);

        boss.signForm(*robotomy);
        boss.executeForm(*robotomy);

        delete robotomy;
    }

    std::cout << "\n===== PRESIDENTIAL TEST =====\n";
    AForm* pardon = intern.makeForm("presidential pardon", "Marvin");

    if (pardon)
    {
        Bureaucrat president("President", 1);

        president.signForm(*pardon);
        president.executeForm(*pardon);

        delete pardon;
    }

    std::cout << "\n===== UNKNOWN FORM TEST =====\n";
    AForm* unknown = intern.makeForm("pizza form", "Bob");

    if (unknown)
        delete unknown;

    std::cout << "\n===== LOW GRADE TEST =====\n";
    AForm* lowTest = intern.makeForm("robotomy request", "LowTarget");

    if (lowTest)
    {
        Bureaucrat low("Low", 150);

        low.signForm(*lowTest);
        low.executeForm(*lowTest);

        delete lowTest;
    }

    return 0;
}