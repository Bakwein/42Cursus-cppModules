/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stunca <stunca@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 00:25:01 by stunca            #+#    #+#             */
/*   Updated: 2023/06/03 00:25:02 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

// # include <iostream>
# include "AAnimal.hpp"
// # include "Colors.hpp"

class Dog : public AAnimal
{
	private:
		Brain	*_brain;
	public:
		Dog( void );
		// Dog( std::string name );
		// Dog( const Dog &rhs );
		~Dog( void );

	void	makeSound( void ) const;
};

#endif // DOG_HPP