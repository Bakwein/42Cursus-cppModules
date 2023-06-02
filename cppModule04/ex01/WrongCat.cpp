/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stunca <stunca@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 00:23:56 by stunca            #+#    #+#             */
/*   Updated: 2023/06/03 00:23:57 by stunca           ###   ########.fr       */
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