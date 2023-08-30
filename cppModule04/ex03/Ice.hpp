#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
    public:
        Ice(void);
        Ice(Ice const &rhs);
        ~Ice(void);

        Ice &operator=(Ice const &rhs);

        virtual AMateria *clone(void)const;
        virtual void use(ICharacter &target);
};

#endif
