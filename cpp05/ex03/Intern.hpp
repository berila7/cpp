#ifndef INTERN_HPP
# define INTERN_HPP

#include <string>
#include "AForm.hpp"

class Intern
{
	public:
		Intern(void);
		Intern(Intern const &other);
		Intern &operator=(Intern const &other);
		~Intern(void);

		AForm* makeForm(std::string formName, std::string target);
		
		
	private:
		AForm* createRobotomy(std::string target);
		AForm* createPresidential(std::string target);
		AForm* createShrubbery(std::string target);

};

#endif