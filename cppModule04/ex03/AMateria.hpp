#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include "ICharacter.hpp"
#include <iostream>
#include <string>

class ICharacter;

class AMateria
{
    protected:
        std::string type;
    public:
    AMateria(void);
    AMateria(AMateria const &rhs);
    virtual ~AMateria(void);

    AMateria(std::string const & type);
    //[...]

    std::string const & getType() const; //Returns the materia type
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);
};

#endif