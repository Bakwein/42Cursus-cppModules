/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stunca <stunca@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 00:20:11 by stunca            #+#    #+#             */
/*   Updated: 2023/06/03 00:20:12 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain( void )
{
	std::cout << "Brain Constructor called." << std::flush << std::endl;
}

Brain::~Brain( void )
{
	std::cout << "Brain Destructor called." << std::flush << std::endl;
}

/**
 * @brief Copying rhs(right hand side) Brain to lhs Brain.
 * 
 * @note STL library func() -> std::copy().
 * @link https://www.geeksforgeeks.org/the-c-standard-template-library-stl/ -> STL libraries.
 * @link https://www.includehelp.com/stl/std-copy-function-with-example.aspx -> I think std::copy() in STL.
 * @link https://linuxhint.com/cpp-std-copy/ -> Sample.
 * @link https://www.geeksforgeeks.org/different-methods-copy-c-stl-stdcopy-copy_n-copy_if-copy_backward/ -> Sample.
 * 
 * @param rhs 
 * @return Brain const& -> lhs Brain.
 */
Brain const	&Brain::operator=( Brain const &rhs )
{
	// std::cout << "Brain Copy Assignment Operator called: "\
	// 	<< std::flush << std::endl;
	// if (this != &rhs)
		// std::copy(rhs._ideas, rhs._ideas + 100, this->_ideas);
	if (this != &rhs)
		for (int i = 0; i < 100; i++)
			this->setIdea(i, rhs.getIdea(i));
	return (*this);
}

/**
 * @brief Setting to Brain's _ideas[index].
 * 
 * @param index 
 * @param idea 
 */
void	Brain::setIdea( int const &index, std::string const &idea )
{
	if (index >= 0 && index < 100)
		this->_ideas[index] = idea;
}

/**
 * @brief Getting Brain's _ideas[index].
 * 
 * @param index 
 * @return std::string const& -> Brain's _ides[index]
 */
std::string	const &Brain::getIdea( int const &index ) const
{
	if (index >= 0 && index < 100)
		return (this->_ideas[index]);
	return (this->_ideas[0]);
}