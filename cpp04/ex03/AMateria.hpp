#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <string>

class AMateria
{
	protected:

	public:
		AMateria(void);
		AMateria(std::string const& type);
		AMateria(AMateria const &other);
		AMateria &operator=(AMateria const &other);
		~AMateria(void);

		std::string const & getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif