#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice"){}

Ice::Ice(Ice const &rhs) : AMateria("ice")
{
    *this = rhs;
}

Ice::~Ice(void){}

Ice &Ice::operator=(Ice const &rhs)
{
    if(this != &rhs)
        this->type = rhs.getType();
    return (*this);
}

AMateria *Ice::clone(void)const
{
    return (new Ice(*this));
}

void Ice::use(ICharacter &target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}