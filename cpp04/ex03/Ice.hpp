#ifndef ICE_HPP
# define ICE_HPP

#include <string>

class Ice
{
	private:
		std::string	type;

	public:
		Ice(void);
		Ice(std::string type);
		Ice(Ice const &other);
		Ice &operator=(Ice const &other);
		~Ice(void);

};

#endif