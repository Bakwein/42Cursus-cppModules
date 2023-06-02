/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stunca <stunca@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 12:53:23 by gsever            #+#    #+#             */
/*   Updated: 2023/06/03 00:24:41 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat( void ) : WrongAnimal("WrongCat")
{
	std::cout << "WrongCat Default Constructor called: " << this->type\
		<< std::flush << std::endl;
}

WrongCat::~WrongCat( void )
{
	std::cout << "WrongCat Destructor called: " << this->type\
		<< std::flush << std::endl;
}

void	WrongCat::makeSound( void ) const
{
	std::cout << "Miyav Miyav: " << this->type\
		<< std::flush << std::endl;
}