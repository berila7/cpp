#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <cstddef>
#include <iostream>

Intern::Intern(void)
{
	std::cout << "Default constructor called" << std::endl;
}

Intern::Intern(Intern const &other)
{
	std::cout << "copy constructor called" << std::endl;
	(void)other;
}

Intern &	Intern::operator=(Intern const &other)
{
	(void)other;
	return (*this);
}

AForm* Intern::createRobotomy(std::string target)
{
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidential(std::string target)
{
    return new PresidentialPardonForm(target);
}

AForm* Intern::createShrubbery(std::string target)
{
    return new ShrubberyCreationForm(target);
}


AForm* Intern::makeForm(std::string formName, std::string target)
{
	AForm* (Intern::*forms[3])(std::string) =
	{
		&Intern::createRobotomy,
		&Intern::createPresidential,
		&Intern::createShrubbery
	};
	int i = 0;
	std::string names[3] =
	{
		"robotomy request",
		"presidential pardon",
		"shrubbery creation"
	};

	while (i < 3 && names[i] != formName)
		i++;

	if (i < 3)
	{
		std::cout << "Intern creates " << formName << std::endl;
		return (this->*forms[i])(target);
	}
	std::cout << "Intern couldn't create " << formName << std::endl;
	return NULL;
}

Intern::~Intern(void)
{
	std::cout << "Destructor constructor" << std::endl;
}