/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stunca <stunca@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 00:20:21 by stunca            #+#    #+#             */
/*   Updated: 2023/06/03 00:20:23 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/**
 * @brief Construct a new Cat:: Cat object
 * 
 * -try-catch-throw(), for memory allocation-
 * @link https://stackoverflow.com/questions/7749066/how-to-catch-out-of-memory-exception-in-c
 * @link https://www.geeksforgeeks.org/if-memory-allocation-using-new-is-failed-in-c-then-how-it-should-be-handled/
 * ------------------------------------------
 */
Cat::Cat( void ) : Animal("Cat")
{
	std::cout << "Cat Default Constructor called: " << this->type\
		<< std::flush << std::endl;
	try
	{
		this->_brain = new Brain();
		std::cout << GREEN "Memory is allocated 'Successfully'!" END\
			<< std::flush << std::endl;
	}
	catch(const std::bad_alloc& e)
	{
		std::cerr << "Memory Allocation is failed: " << e.what() << "bytes: "\
			<< sizeof(Brain) << std::flush << std::endl;
	}
}

// Cat::Cat( std::string name ) : Animal("Cat")
// {
// 	std::cout << "Cat Name Constructor called: " << this->type\
// 		<< std::flush << std::endl;
// }

// Cat::Cat( const Cat &rhs ) : Animal(rhs.type)
// {
// 	std::cout << "Cat Copy Constructor called: " << this->type\
// 		<< std::flush << std::endl;
// }

Cat::~Cat( void )
{
	std::cout << "Cat Destructor called: " << this->type\
		<< std::flush << std::endl;
	delete this->_brain;
}

void	Cat::makeSound( void ) const
{
	std::cout << "Miyav Miyav: " << this->type\
		<< std::flush << std::endl;
}

Brain	&Cat::getBrain( void ) const
{
	return (*this->_brain);
}