/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stunca <stunca@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 12:53:34 by gsever            #+#    #+#             */
/*   Updated: 2023/06/03 00:22:26 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal
{
	protected:
		std::string type;
	public:
		WrongAnimal( void );
		WrongAnimal( std::string name );
		WrongAnimal( const WrongAnimal &rhs );
		virtual ~WrongAnimal( void );// Virtual ~WrongAnimal Destructor for Colon type can allowing to free.

		std::string		getType( void ) const;
		virtual void	makeSound( void ) const;// If WrongAnimals dog or cat have same func(), not calling this func. Calling own self func().
};

#endif // WRONGANIMAL_HPP