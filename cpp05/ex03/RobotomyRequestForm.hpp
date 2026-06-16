#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <string>

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm const &instance);
		RobotomyRequestForm &operator=(RobotomyRequestForm const &rhs);
		virtual void executeAction() const;
		virtual ~RobotomyRequestForm(void);

	private:

};

#endif