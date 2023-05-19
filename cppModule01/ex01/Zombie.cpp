/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stunca <stunca@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 19:40:38 by stunca            #+#    #+#             */
/*   Updated: 2023/05/19 19:40:39 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// ZOMBIE IN STACK

Zombie::Zombie()
{

}

Zombie::Zombie(std::string Name)
{
    this->Name = Name;
}

Zombie::~Zombie()
{
    std::cout << "Zombie(" << this->Name << ") has been destroyed." << std::endl;
}

void Zombie::announce(void)
{
    std::cout << this->getName() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

std::string Zombie::getName(void)const
{
    return Name;
}

void Zombie::setName(std::string const Name)
{
    this->Name = Name;
}