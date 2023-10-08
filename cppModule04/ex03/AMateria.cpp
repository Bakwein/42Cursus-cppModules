#include "AMateria.hpp"

AMateria::AMateria( void ) : type("Default")
{
}

AMateria::AMateria( std::string const &type ) : type(type)
{
}

AMateria::AMateria( AMateria const &rhs ) : type(rhs.type)
{
}

AMateria::~AMateria( void )
{
}

std::string const	&AMateria::getType( void ) const
{
	return (this->type);
}

AMateria	*AMateria::clone( void ) const
{
	return ((AMateria*)this);
}

void	AMateria::use( ICharacter &target )
{
	std::cout << "AMateria " << this->type << " used on "\
		<< target.getName() << std::flush << std::endl;
}