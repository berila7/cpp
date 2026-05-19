#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(std::string const& name, int grade)
	: 
	_name(name),
	_grade(grade)
{
	std::cout << "parametrized constructor called" << std::endl;
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(Bureaucrat const &other) : 
	_name(other._name),
	_grade(other._grade)
{
	std::cout << "Copy constructor called" << std::endl;
}

Bureaucrat &	Bureaucrat::operator=(Bureaucrat const &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		_grade = other._grade;
	return (*this);
}

void Bureaucrat::incrementGrade() {
    if (_grade - 1 < 1)
        throw GradeTooHighException();
    _grade--;
}

void Bureaucrat::decrementGrade() {
    if (_grade + 1 > 150)
        throw GradeTooLowException();
    _grade++;
}

std::string	Bureaucrat::getName() const
{
	return (_name);
}

int	Bureaucrat::getGrade() const
{
	return (_grade);
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade is too hight!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade is too low!");
}

void Bureaucrat::signForm(Form& form) {
    try {
        form.beSigned(*this);
        std::cout << _name << " signed " << form.getName() << std::endl;
    }
    catch (std::exception& e) {
        std::cout << _name << " couldn't sign " << form.getName() 
                  << " because " << e.what() << std::endl;
    }
}

std::ostream& operator<<(std::ostream& out, Bureaucrat const& b) {
    out << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return out;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Destructor called" << std::endl;
}
