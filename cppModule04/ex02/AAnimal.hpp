/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stunca <stunca@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 00:25:42 by stunca            #+#    #+#             */
/*   Updated: 2023/06/03 00:25:43 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>
# include "Colors.hpp"
# include "Brain.hpp"

/**
 * @brief Abstract Class
 * 
 * 		Virtual destructor:
	A virtual destructor is used to free up the memory space allocated by 
	the derived class object or instance while deleting instances of the derived
	class using a base class pointer object. A base or parent class destructor
	use the virtual keyword that ensures both base class and the derived class 
	destructor will be called at run time, but it called the derived class first
	and then base class to release the space occupied by both destructors.

	Every destructor down gets called no matter what. virtual makes sure it
	starts at the top instead of the middle.

	Virtual destructors are useful when you might potentially delete an instance 
	of a derived class through a pointer to base class:
 * 
 * @fn makeSound(); There ( = 0 ) meaning; You can't create this class anywhere,
 *  you can just inheritance this class.
 * @note Just = 0, not 1 or -253 etc.
 * @note We are created a 'Abstract Class' therefore we need to add 'A' prefix
 *  to .cpp file's name.
 */
class AAnimal
{
	protected:
		std::string type;
	public:
		AAnimal( void );
		AAnimal( std::string name );
		AAnimal( const AAnimal &rhs );
		virtual ~AAnimal( void );// Virtual ~AAnimal Destructor for Colon type can allowing to free.

		std::string		getType( void ) const;
		virtual void	makeSound( void ) const = 0;// If AAnimals dog or cat have same func(), not calling this func. Calling own self func().
};

#endif // AANIMAL_HPP