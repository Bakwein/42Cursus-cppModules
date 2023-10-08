#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria	*_materias[4];
	public:
		MateriaSource( void );
		MateriaSource( MateriaSource const &rhs );
		~MateriaSource( void );

		MateriaSource	&operator=( MateriaSource const &rhs );

		void		learnMateria( AMateria* );
		AMateria	*createMateria( std::string const &type );
		AMateria	*getMateria( std::string const &type );
};

#endif // MATERIASOURCE_HPP