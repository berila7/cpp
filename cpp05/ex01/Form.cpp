#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

Form::Form(std::string const& name, int gradeToSign, int gradeToExecute)
	:
	_name(name),
	_isSigned(false),
	_gradeToSign(gradeToSign),
	_gradeToExecute(gradeToExecute)
{
	std::cout << "Constructor called" << std::endl;
}

Form::Form(Form const &other)
	:
	_name(other._name),
	_isSigned(other._isSigned),
	_gradeToSign(other._gradeToSign),
	_gradeToExecute(other._gradeToExecute)
{
	std::cout << "Copy Constructor called" << std::endl;
}

Form&	Form::operator=(Form const &other)
{
	std::cout << "Copy assignment called" << std::endl;
	if (this != &other)
		_isSigned = other._isSigned;
	return (*this);
}

std::string	Form::getName() const
{
	return (_name);
}

bool	Form::getIsSigned() const
{
	return (_isSigned);
}

int	Form::getGradeToSign() const
{
	return (_gradeToSign);
}

int	Form::getGradeToExecute() const
{
	return (_gradeToExecute);
}

void Form::beSigned(Bureaucrat const& bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_isSigned = true;
}

Form::~Form(void)
{
	std::cout << "Destructor called" << std::endl;
}
