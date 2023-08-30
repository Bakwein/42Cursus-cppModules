#include "AMateria.hpp"

AMateria::AMateria(void) : type("default"){}

AMateria::AMateria(AMateria const &rhs) : type(rhs.getType()){}

AMateria::~AMateria(void){}

AMateria::AMateria(std::string const &type) :type(type){}

std::string  const& AMateria::getType()const{return type;}

AMateria *AMateria::clone()const
{
    return((AMateria*)this);
}

void AMateria::use(ICharacter& target)
{
    std::cout << "AMateria " << this->type << " used on "
 << target.getName() << std::endl;}