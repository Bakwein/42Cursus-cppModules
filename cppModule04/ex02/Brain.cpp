/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stunca <stunca@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 00:25:37 by stunca            #+#    #+#             */
/*   Updated: 2023/06/03 00:25:38 by stunca           ###   ########.fr       */
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