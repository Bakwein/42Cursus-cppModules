#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include "ICharacter.hpp"
#include <iostream>
#include <string>

class ICharacter;

class AMateria
{
	protected:
		std::string	type;
	public:
		AMateria( void );
		AMateria( std::string const &type );
		AMateria( AMateria const &rhs );
		virtual	~AMateria( void );

		std::string const	&getType() const;

		virtual AMateria	*clone() const = 0;
		virtual void		use( ICharacter &target );
};

#endif