#include "Cure.hpp"

Cure::Cure( void ) : AMateria("cure")
{
}

Cure::Cure( Cure const &rhs ) : AMateria("cure")
{
	*this = rhs;
}

Cure::~Cure( void )
{
}

Cure	&Cure::operator=( Cure const &rhs )
{
	if (this != &rhs)
		this->type = rhs.getType();
	return (*this);
}

AMateria	*Cure::clone( void ) const
{
	return (new Cure(*this));
}

void	Cure::use( ICharacter &target )
{
	std::cout << "* heals " << target.getName() << "'s wounds *"<< std::endl;
}