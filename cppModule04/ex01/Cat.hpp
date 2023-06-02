/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stunca <stunca@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 00:20:27 by stunca            #+#    #+#             */
/*   Updated: 2023/06/03 00:20:29 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

// # include <iostream>
# include "Animal.hpp"
// # include "Colors.hpp"

class Cat : public Animal
{
	private:
		Brain	*_brain;
	public:
		Cat( void );
		// Cat( std::string name );
		// Cat( const Cat &rhs );
		~Cat( void );

	void	makeSound( void ) const;
	Brain	&getBrain( void ) const;
};

#endif // CAT_HPP