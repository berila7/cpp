#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>

class AForm;

class Bureaucrat
{
    public:
        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };


    private:
        const std::string _name;
        int _grade;
	public:
		Bureaucrat(std::string const& name, int grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);
        void signForm(AForm& form);
        void incrementGrade();
        void decrementGrade();
        int	getGrade( void ) const;
	    std::string	getName( void ) const;
        void executeForm(AForm const& form) const;
		~Bureaucrat(void);
};
std::ostream& operator<<(std::ostream& out, Bureaucrat const& b);
#endif