/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stunca <stunca@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 19:38:16 by stunca            #+#    #+#             */
/*   Updated: 2023/05/19 19:38:18 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// ZOMBIE IN STACK

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
    std::cout << this->Name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}