/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stunca <stunca@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 00:12:15 by stunca            #+#    #+#             */
/*   Updated: 2023/06/03 00:12:16 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat( void ) : Animal("Cat")
{
	std::cout << "Cat Default Constructor called: " << this->type\
		<< std::flush << std::endl;
}

Cat::Cat( std::string name ) : Animal(name)
{
 	std::cout << "Cat Name Constructor called: " << this->type<< std::endl;
}

 Cat::Cat( const Cat &rhs ) : Animal(rhs.type)
 {
 	std::cout << "Cat Copy Constructor called: " << this->type << std::endl;
 }

Cat::~Cat( void )
{
	std::cout << "Cat Destructor called: " << this->type\
		<< std::flush << std::endl;
}

void	Cat::makeSound( void ) const
{
	std::cout << "Miyav Miyav: " << this->type\
		<< std::flush << std::endl;
}