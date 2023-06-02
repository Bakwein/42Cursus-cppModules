/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stunca <stunca@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 00:20:16 by stunca            #+#    #+#             */
/*   Updated: 2023/06/03 00:20:17 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain
{
	private:
		std::string _ideas[100];
	public:
		Brain( void );
		// Brain( std::string name );
		// Brain( const Brain &rhs );
		~Brain( void );

		Brain const			&operator=( Brain const &rhs );

		void				setIdea( int const &index, std::string const &idea );
		std::string const	&getIdea( int const &index) const;
};

#endif // BRAIN_HPP