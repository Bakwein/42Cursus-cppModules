/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stunca <stunca@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 00:12:17 by stunca            #+#    #+#             */
/*   Updated: 2023/06/03 00:12:18 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
	protected:
		std::string type;
	public:
		Animal( void );
		Animal( std::string name );
		Animal( const Animal &rhs );
		virtual ~Animal( void );// Virtual ~Animal Destructor for Colon type can allowing to free.

		std::string		getType( void ) const;
		virtual void	makeSound( void ) const;// If animals dog or cat have same func(), not calling this func. Calling own self func().
};

#endif // ANIMAL_HPP