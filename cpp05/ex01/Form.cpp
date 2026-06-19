#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

Form::Form()
	:
	_name("default"),
	_isSigned(false),
	_gradeToSign(150),
	_gradeToExecute(150)
{
	std::cout << "default constructor called" << std::endl;
}

Form::Form(std::string const& name, int gradeToSign, int gradeToExecute)
	:
	_name(name),
	_isSigned(false),
	_gradeToSign(gradeToSign),
	_gradeToExecute(gradeToExecute)
{
	std::cout << "Constructor called" << std::endl;
	
	// Validate gradeToSign
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw GradeTooHighException();
	if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw GradeTooLowException();
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

const char* Form::GradeTooHighException::what() const throw()
{
    return "Form grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Form grade is too low!";
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

std::ostream& operator<<(std::ostream& out, Form const& form)
{
    out << "Form " << form.getName() 
        << " [signed: " << (form.getIsSigned() ? "yes" : "no")
        << ", grade to sign: " << form.getGradeToSign()
        << ", grade to execute: " << form.getGradeToExecute() << "]";
    return out;
}

Form::~Form(void)
{
	std::cout << "Destructor called" << std::endl;
}
