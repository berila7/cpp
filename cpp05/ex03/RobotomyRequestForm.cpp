#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(void)
	: AForm("RobotomyRequestForm", 72, 45, "defaultTarget")
{
	std::cout << "Robotomy default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: AForm("RobotomyRequestForm", 72, 45, target)
{
	std::cout << "Robotomy parameterized constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other)
	: AForm(other)
{
	std::cout << "Robotomy copy constructor called" << std::endl;
}

RobotomyRequestForm &	RobotomyRequestForm::operator=(RobotomyRequestForm const &other)
{
	if (this != &other)
		AForm::operator=(other);
	return (*this);
}

void RobotomyRequestForm::executeAction() const
{
	int num = std::rand() % 2;
	std::cout << "BZZZZZZZZZZZZZZ" << std::endl;
	if (num == 0)
		std::cout << getTarget() << " has been robotomized successfully" << std::endl;
	else
	 	std::cout << getTarget() << " Robotomy failed" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "Roboto destructor called" << std::endl;
}
