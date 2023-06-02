/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stunca <stunca@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 00:21:03 by stunca            #+#    #+#             */
/*   Updated: 2023/06/03 00:21:28 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

// # include <iostream>
# include "Animal.hpp"
// # include "Colors.hpp"

class Dog : public Animal
{
	private:
		Brain	*_brain;
	public:
		Dog( void );
		// Dog( std::string name );
		// Dog( const Dog &rhs );
		~Dog( void );

	void	makeSound( void ) const;
	Brain	&getBrain( void ) const;
};

#endif // DOG_HPP