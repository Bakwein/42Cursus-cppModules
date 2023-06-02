/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 12:53:53 by gsever            #+#    #+#             */
/*   Updated: 2023/02/23 13:05:10 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void ) : type("WrongDefault")
{
	std::cout << "WrongAnimal Default Constructor called: " << this->type\
		<< std::flush << std::endl;
}

WrongAnimal::WrongAnimal( std::string name ) : type(name)
{
	std::cout << "WrongAnimal Name Constructor called: " << this->type\
		<< std::flush << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal &rhs ) : type(rhs.type)
{
	std::cout << "WrongAnimal Copy Constructor called: " << this->type\
		<< std::flush << std::endl;
}

WrongAnimal::~WrongAnimal( void )
{
	std::cout << "WrongAnimal Destructor called: " << this->type\
		<< std::flush << std::endl;
}

std::string	WrongAnimal::getType( void ) const
{
	return (this->type);
}

void	WrongAnimal::makeSound( void ) const
{
	std::cout << "WrongAnimal makeSound called: " << this->type\
		<< std::flush << std::endl;
}