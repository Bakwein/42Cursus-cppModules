/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stunca <stunca@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 19:51:34 by stunca            #+#    #+#             */
/*   Updated: 2023/05/19 19:51:36 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name):name(name)
{
    std::cout << GREEN<<this->name << " is ready to fight!" << END << std::endl;
}

HumanB::~HumanB()
{
    std::cout << RED <<  name << " is destroyed!"<< END << std::endl;
}

void HumanB::attack()
{
    std::cout << YELLOW << this->name << " attacks with their " << this->w->getType() << END <<std::endl;
}

void HumanB::setWeapon(Weapon &w)
{
    this->w = &w;
}
