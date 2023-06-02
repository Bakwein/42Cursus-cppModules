/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stunca <stunca@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 00:12:03 by stunca            #+#    #+#             */
/*   Updated: 2023/06/03 00:12:04 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void ) : type("WrongDefault")
{
	std::cout << "WrongAnimal Default Constructor called: " << this->type<< std::endl;
}

WrongAnimal::WrongAnimal( std::string name ) : type(name)
{
	std::cout << "WrongAnimal Name Constructor called: " << this->type<< std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal &rhs ) : type(rhs.type)
{
	std::cout << "WrongAnimal Copy Constructor called: " << this->type<< std::endl;
}

WrongAnimal::~WrongAnimal( void )
{
	std::cout << "WrongAnimal Destructor called: " << this->type << std::endl;
}

std::string	WrongAnimal::getType( void ) const
{
	return (this->type);
}

void	WrongAnimal::makeSound( void ) const
{
	std::cout << "WrongAnimal makeSound called: " << this->type << std::endl;
}