#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(void)
	: AForm("ShrubberyCreationForm", 145, 137, "defaultTarget")
{
	std::cout << "Shrubbery Default constructor called" << std::endl;
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

	std::string fileName = getTarget() + "_shrubbery";
	std::ofstream myFile(fileName.c_str());

    if (!myFile.is_open()) {
        std::cout << "Failed to open file!" << std::endl;
		return;
    }
	myFile	<< "   /\\\n"
			<< "  /**\\\n"
 			<< " /****\\\n"
  			<< "   ||\n";
	myFile.close();
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "Shrubbery destructor called" << std::endl;
}