#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
    private:
        AMateria *materias[4];
    public:
        MateriaSource(void);
        MateriaSource(MateriaSource const &rhs);
        ~MateriaSource(void);

        MateriaSource &operator=(MateriaSource const &rhs);

        void learnMateria(AMateria*);
        AMateria* createMateria(std::string const &type);
};


#endif