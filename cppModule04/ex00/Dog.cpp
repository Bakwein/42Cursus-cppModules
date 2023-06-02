/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stunca <stunca@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 00:12:11 by stunca            #+#    #+#             */
/*   Updated: 2023/06/03 00:12:12 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog( void ) : Animal("Dog")
{
	std::cout << "Dog Default Constructor called: " << this->type<< std::endl;
}

Dog::Dog( std::string name ) : Animal(name)
{
 	std::cout << "Dog Name Constructor called: " << this->type<< std::endl;
}

 Dog::Dog( const Dog &rhs ) : Animal(rhs.type)
 {
 	std::cout << "Dog Copy Constructor called: " << this->type << std::endl;
 }

Dog::~Dog( void )
{
	std::cout << "Dog Destructor called: " << this->type << std::endl;
}

void	Dog::makeSound( void ) const
{
	std::cout << "Hav Hav Hav: " << this->type<< std::endl;
}