#ifndef FORM_HPP
# define FORM_HPP

#include <string>

class Bureaucrat;

class Form {
public:
	class GradeTooHighException : public std::exception {
		public:
			virtual const char* what() const throw();
	};
	
	class GradeTooLowException : public std::exception {
		public:
			virtual const char* what() const throw();
	};

private:
	const std::string _name;
	bool _isSigned;
	const int _gradeToSign;
	const int _gradeToExecute;

public:
	Form(std::string const& name, int gradeToSign, int gradeToExecute);

	Form(Form const& other);
	Form& operator=(Form const& other);

	~Form();

	std::string getName() const;
	bool getIsSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;

	void beSigned(Bureaucrat const& bureaucrat);
};

std::ostream& operator<<(std::ostream& out, Form const& form);

#endif