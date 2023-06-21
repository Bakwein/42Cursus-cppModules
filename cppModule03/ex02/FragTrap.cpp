/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stunca <stunca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 18:01:10 by stunca            #+#    #+#             */
/*   Updated: 2023/05/31 18:01:12 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap( void ) : ClapTrap()
{
	this->name = "Default";
	this->hitPoint = 100;
	this->energyPoint = 100;
	this->attackDamage = 30;
	std::cout << "FragTrap Default Constructor called: " << this->name
		 << std::endl;
}

FragTrap::FragTrap( std::string name ) : ClapTrap(name)
{
	this->name = name;
	this->hitPoint = 100;
	this->energyPoint = 100;
	this->attackDamage = 30;
	std::cout << "FragTrap Name Constructor called: " << this->name
		 << std::endl;
}

FragTrap::FragTrap( const FragTrap &rhs ) : ClapTrap(rhs)
{
	std::cout << "FragTrap " << "Copy Constructor called: " << this->name
		 << std::endl;
}

FragTrap::~FragTrap( void )
{
	std::cout << "FragTrap Destructor called: " << this->name
		<< std::endl;
}

FragTrap	&FragTrap::operator=( const FragTrap &rhs )
{
	ClapTrap::operator=(rhs);
	std::cout << "FragTrap " << "Copy Assignment Operator called: "
		<< this->name  << std::endl;
	return (*this);
}

void	FragTrap::highFivesGuys( void )
{
	std::cout << "FragTrap " << this->name << " positive high fives request!"
		 << std::endl;
}
