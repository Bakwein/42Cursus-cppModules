/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stunca <stunca@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 00:24:33 by stunca            #+#    #+#             */
/*   Updated: 2023/06/03 00:24:35 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

// # include <iostream>
# include "WrongAnimal.hpp"
// # include "Colors.hpp"

class WrongCat : public WrongAnimal
{
	// protected:
		// std::string type;
	public:
		WrongCat( void );
		// WrongCat( std::string name );
		// WrongCat( const WrongCat &rhs );
		~WrongCat( void );

	void	makeSound( void ) const;
};

#endif // WRONGCAT_HPP