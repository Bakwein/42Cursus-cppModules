/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stunca <stunca@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 00:21:22 by stunca            #+#    #+#             */
/*   Updated: 2023/06/03 00:22:18 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/**
 * @brief Construct a new Dog:: Dog object
 * 
 * -try-catch-throw(), for memory allocation-
 * @link https://stackoverflow.com/questions/7749066/how-to-catch-out-of-memory-exception-in-c
 * @link https://www.geeksforgeeks.org/if-memory-allocation-using-new-is-failed-in-c-then-how-it-should-be-handled/
 * ------------------------------------------
 */
Dog::Dog( void ) : Animal("Dog")
{
	std::cout << "Dog Default Constructor called: " << this->type\
		<< std::flush << std::endl;
	try
	{
		this->_brain = new Brain();
		std::cout << "Memory is allocated 'Successfully'!" \
			<< std::flush << std::endl;
	}
	catch(const std::bad_alloc& e)
	{
		std::cerr << "Memory Allocation is failed: " << e.what() << "bytes: "\
			<< sizeof(Brain) << std::flush << std::endl;
	}
}

// Dog::Dog( std::string name ) : Animal("Dog")
// {
// 	std::cout << "Dog Name Constructor called: " << this->type\
// 		<< std::flush << std::endl;
// }

// Dog::Dog( const Dog &rhs ) : Animal(rhs.type)
// {
// 	std::cout << "Dog Copy Constructor called: " << this->type\
// 		<< std::flush << std::endl;
// }

Dog::~Dog( void )
{
	std::cout << "Dog Destructor called: " << this->type\
		<< std::flush << std::endl;
	delete this->_brain;
}

void	Dog::makeSound( void ) const
{
	std::cout << "Hav Hav Hav: " << this->type\
		<< std::flush << std::endl;
}

Brain	&Dog::getBrain( void ) const
{
	return (*this->_brain);
}