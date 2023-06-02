/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stunca <stunca@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 00:12:13 by stunca            #+#    #+#             */
/*   Updated: 2023/06/03 00:12:14 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

// # include <iostream>
# include "Animal.hpp"

class Cat : public Animal
{
	protected:
		 std::string type;
         //std::string name;
	public:
		Cat( void );
		Cat( std::string name );
		Cat( const Cat &rhs );
		~Cat( void );

	void	makeSound( void ) const;
};

#endif // CAT_HPP