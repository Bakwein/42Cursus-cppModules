#include "MateriaSource.hpp"

MateriaSource::MateriaSource( void )
{
	for (int i = 0; i < 4; i++)
		this->_materias[i] = NULL;
}

MateriaSource::MateriaSource( MateriaSource const &rhs )
{
    for (int i = 0;i <4;i++)
        this->_materias[i] = rhs._materias[i];
	*this = rhs;
}

MateriaSource::~MateriaSource( void )
{
    for(int i = 0;i < 4; i++)
    {
        delete this->_materias[i];
    }
}

MateriaSource	&MateriaSource::operator=( MateriaSource const &rhs )
{
	if (this != &rhs)
		for (int i = 0; i < 4; i++)
			this->_materias[i] = rhs._materias[i];
	return (*this);
}

void	MateriaSource::learnMateria( AMateria* materia)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_materias[i] == NULL)
		{
			this->_materias[i] = materia;
			return ;
		}
	}
}

AMateria	*MateriaSource::createMateria( std::string const &type )
{
	for (int i = 0; i < 4; i++)
		if (this->_materias[i] && this->_materias[i]->getType() == type)
			return (this->_materias[i]->clone());
	return (NULL);
}

AMateria	*MateriaSource::getMateria( std::string const &type )
{
	for (int i = 0; i < 4; i++)
		if (this->_materias[i] && this->_materias[i]->getType() == type)
			return (this->_materias[i]);
	return (NULL);
}