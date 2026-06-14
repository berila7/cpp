#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

int main()
{
	AForm *form = new ShrubberyCreationForm("home");
	Bureaucrat first("bob", 32);
	form->execute(first);
	delete form;
	return 0;
}