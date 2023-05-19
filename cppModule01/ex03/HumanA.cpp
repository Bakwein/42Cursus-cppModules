/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stunca <stunca@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 19:51:22 by stunca            #+#    #+#             */
/*   Updated: 2023/05/19 19:51:23 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"

HumanA::HumanA(std::string name , Weapon &w) : name(name),w(w)
{
    std::cout << GREEN<<this->name << " is ready to fight!" << END << std::endl;
}

HumanA::~HumanA()
{
    std::cout << RED << name << " is destroyed!"<<END<<std::endl;
}

//<name> attacks with their <weapon type> 
void HumanA::attack()
{
    std::cout << YELLOW <<this->name << " attacks with their " << this->w.getType() <<  END <<std::endl;
}
