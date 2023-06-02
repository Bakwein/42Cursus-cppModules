/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stunca <stunca@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 00:12:10 by stunca            #+#    #+#             */
/*   Updated: 2023/06/03 00:12:10 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

// # include <iostream>
# include "Animal.hpp"

class Dog : public Animal
{
	protected:
		 std::string type;
	public:
		Dog( void );
		 Dog( std::string name );
		 Dog( const Dog &rhs );
		~Dog( void );

	void	makeSound( void ) const;
};

#endif // DOG_HPP