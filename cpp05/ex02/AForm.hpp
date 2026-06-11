#ifndef AFORM_HPP
# define AFORM_HPP

#include <string>
#include <exception>

class Bureaucrat;

class AForm {
public:
	class GradeTooHighException : public std::exception {
		public:
			virtual const char* what() const throw();
	};
	
	class GradeTooLowException : public std::exception {
		public:
			virtual const char* what() const throw();
	};

	class FormNotSignedException : public std::exception {
    	public:
        	virtual const char* what() const throw();
    };

private:
	const std::string	_name;
	bool				_isSigned;
	const int			_gradeToSign;
	const int			_gradeToExecute;
	std::string	_target;

public:
	AForm(std::string const& name, int gradeToSign, int gradeToExecute, std::string const target);

	AForm(AForm const& other);
	AForm& operator=(AForm const& other);

	virtual	~AForm();

	std::string getName() const;
	bool getIsSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
	std::string	getTarget() const;
    void execute(Bureaucrat const& executor) const;
    
    virtual void executeAction() const = 0;

	void beSigned(Bureaucrat const& bureaucrat);
};

std::ostream& operator<<(std::ostream& out, AForm const& form);

#endif