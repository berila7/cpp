#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

AForm::AForm(std::string const& name, int gradeToSign, int gradeToExecute, std::string const target)
	:
	_name(name),
	_isSigned(false),
	_gradeToSign(gradeToSign),
	_gradeToExecute(gradeToExecute),
	_target(target)
{
	std::cout << "Constructor called" << std::endl;
	
	// Validate gradeToSign
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw GradeTooHighException();
	if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw GradeTooLowException();
}

AForm::AForm(AForm const &other)
	:
	_name(other._name),
	_isSigned(other._isSigned),
	_gradeToSign(other._gradeToSign),
	_gradeToExecute(other._gradeToExecute),
	_target(other._target)
{
	std::cout << "Copy Constructor called" << std::endl;
}

AForm&	AForm::operator=(AForm const &other)
{
	std::cout << "Copy assignment called" << std::endl;
	if (this != &other)
		_isSigned = other._isSigned;
	return (*this);
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return ("Form grade is too high!");
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return ("Form grade is too low!");
}

const char*	AForm::FormNotSignedException::what() const throw()
{
	return ("form not signed");
}

std::string	AForm::getName() const
{
	return (_name);
}

bool	AForm::getIsSigned() const
{
	return (_isSigned);
}

int	AForm::getGradeToSign() const
{
	return (_gradeToSign);
}

std::string	AForm::getTarget() const
{
	return (_target);
}

int	AForm::getGradeToExecute() const
{
	return (_gradeToExecute);
}

void AForm::beSigned(Bureaucrat const& bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_isSigned = true;
}

void AForm::execute(Bureaucrat const& executor) const
{
	if (!_isSigned)
		throw FormNotSignedException();
	else if (executor.getGrade() > _gradeToExecute)
		throw GradeTooLowException();
	executeAction();
}


std::ostream& operator<<(std::ostream& out, AForm const& form)
{
    out << "Form " << form.getName() 
        << " [signed: " << (form.getIsSigned() ? "yes" : "no")
        << ", grade to sign: " << form.getGradeToSign()
        << ", grade to execute: " << form.getGradeToExecute() << "]";
    return out;
}

AForm::~AForm(void)
{
	std::cout << "Destructor called" << std::endl;
}
