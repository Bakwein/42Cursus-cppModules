#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
    for(int i = 0;i < 4;i++)
    {
        this->materias[i] = NULL;
    }
}

MateriaSource::MateriaSource(MateriaSource const &rhs)
{
    *this = rhs;
}

MateriaSource::~MateriaSource(void)
{
    //???
    /*
    for(int i = 0;i < 4 ; i++)
    {
        delete this->materias[i];
    }
    */
}

MateriaSource &MateriaSource::operator=(MateriaSource const &rhs)
{
    if(this != &rhs)
    {
        for(int i = 0; i < 4 ; i++)
        {
            this->materias[i] = rhs.materias[i];
        }
    }
    return(*this);
}

void MateriaSource::learnMateria(AMateria *met)
{
    for(int i = 0; i < 4 ; i++)
    {
        if(materias[i] == NULL)
        {
            materias[i] = met;
            return ;
        }
    }
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
    for(int i = 0; i < 4 ; i++)
    {
        if(this->materias[i] && this->materias[i]->getType() == type)
            return(this->materias[i]);
    }
    return (NULL);
}