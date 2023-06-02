/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stunca <stunca@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 00:25:19 by stunca            #+#    #+#             */
/*   Updated: 2023/06/03 00:25:20 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

// # include <iostream>
# include "AAnimal.hpp"
// # include "Colors.hpp"

class Cat : public AAnimal
{
	private:
		Brain	*_brain;
	public:
		Cat( void );
		// Cat( std::string name );
		// Cat( const Cat &rhs );
		~Cat( void );

	void	makeSound( void ) const;
};

#endif // CAT_HPP