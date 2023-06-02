/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stunca <stunca@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 00:20:01 by stunca            #+#    #+#             */
/*   Updated: 2023/06/03 00:20:03 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal( void ) : type("Default")
{
	std::cout << "Animal Default Constructor called: " << this->type\
		<< std::flush << std::endl;
}

Animal::Animal( std::string name ) : type(name)
{
	std::cout << "Animal Name Constructor called: " << this->type\
		<< std::flush << std::endl;
}

Animal::Animal( const Animal &rhs ) : type(rhs.type)
{
	std::cout << "Animal Copy Constructor called: " << this->type\
		<< std::flush << std::endl;
}

Animal::~Animal( void )
{
	std::cout << "Animal Destructor called: " << this->type\
		<< std::flush << std::endl;
}

std::string	Animal::getType( void ) const
{
	return (this->type);
}

void	Animal::makeSound( void ) const
{
	std::cout << "Animal makeSound called: " << this->type\
		<< std::flush << std::endl;
}