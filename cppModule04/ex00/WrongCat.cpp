/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stunca <stunca@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 00:11:54 by stunca            #+#    #+#             */
/*   Updated: 2023/06/03 00:11:55 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat( void ) : WrongAnimal("WrongCat")
{
	std::cout << "WrongCat Default Constructor called: " << this->type\
		<< std::flush << std::endl;
}

WrongCat::WrongCat( std::string name ) : WrongAnimal(name)
{
 	std::cout << "Wrong Cat Name Constructor called: " << this->type<< std::endl;
}

 WrongCat::WrongCat( const WrongCat &rhs ) : WrongAnimal(rhs.type)
 {
 	std::cout << "Wrong Cat Copy Constructor called: " << this->type << std::endl;
 }

WrongCat::~WrongCat( void )
{
	std::cout << "WrongCat Destructor called: " << this->type<< std::endl;
}

void	WrongCat::makeSound( void ) const
{
	std::cout << "Miyav Miyav: " << this->type\
		<< std::flush << std::endl;
}