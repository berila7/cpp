#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(void)
	: AForm("ShrubberyCreationForm", 145, 137, "defaultTraget")
{
	std::cout << "Default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: AForm("ShrubberyCreationForm", 145, 137, target)
{
	std::cout << "parameterized constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other)
	: AForm(other)
{
	std::cout << "copy constructor called" << std::endl;
}

ShrubberyCreationForm &	ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other)
{
	if (this != &other)
		AForm::operator=(other);
	return (*this);
}

void ShrubberyCreationForm::executeAction() const
{
	std::ofstream myFile(getTarget() + "_shrubbery");

    if (!myFile.is_open()) {
        std::cout << "Failed to open file!" << std::endl;
		return; 
    }
	myFile << "   /\
  				 /**\
 				/****\
  				  ||";
	myFile.close();
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "destructor called" << std::endl;
}