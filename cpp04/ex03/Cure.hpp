#ifndef CURE_HPP
# define CURE_HPP

#include <string>

class Cure
{
	private:
		std::string	type;
	public:
		Cure(void);
		Cure(std::string value);
		Cure(Cure const &other);
		Cure &operator=(Cure const &other);
		~Cure(void);

};

#endif