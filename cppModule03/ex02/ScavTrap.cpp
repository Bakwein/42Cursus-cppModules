/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stunca <stunca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:27:27 by stunca            #+#    #+#             */
/*   Updated: 2023/05/31 13:27:30 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
    this->name = "Default";
    this->hitPoint = 100;
    this->energyPoint = 50;
    this->attackDamage = 20;
    this->isGuardOn = false;
    std::cout<< B_BLUE << "ScavTrap "<< this->name <<" is created with Default ScavTrap Constructor" << END <<std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    this->name = name;
    this->hitPoint = 100;
    this->energyPoint = 50;
    this->attackDamage = 20;
    this->isGuardOn = false;
    std::cout <<B_BLUE <<"ScavTrap " << this->name << " is created with ScavTrap Name Constructor" << END << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &st) : ClapTrap(st)
{
    this->isGuardOn = st.isGuardOn;
    std::cout << "ScavTrap " << this->name << " is created with ScavTrap Copy Constructor" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &st)
{
    ClapTrap::operator=(st);
    this->isGuardOn = st.isGuardOn;
    std::cout<< B_BLUE << "Scavtrap " << this->name  <<" is created with Copy Assisgnment Opeator" << END<< std::endl;
    return (*this);
}

ScavTrap::~ScavTrap(void)
{
    std::cout<< B_RED << "ScavTrap " << this->name << "\'s Destructor" << END << std::endl; 
}

void ScavTrap::attack(const std::string &target)
{
    if(!(this->isAlive()))
        return ;
    std::cout << B_YELLOW <<"ScavTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << END <<std::endl;
    this->energyPoint--;
    std::cout << B_BLUE <<"Remaining energy point -> " << this->energyPoint << END << std::endl;
}

void ScavTrap::takeDamage(unsigned int amount)
{
    if(this->isGuardOn == true)
    {
        std::cout << B_YELLOW <<"ScavTrap " << this->name << " can't take any damage becuse of it's Guard Gate Mode!" << END << std::endl;
    }
    else
    {
        ClapTrap::takeDamage(amount);
    }
}

void ScavTrap::guardGate(void)
{
    if(this->hitPoint>0)
    {
        this->isGuardOn = true;
        std::cout << B_GREEN << "ScavTrap " << this->name << " is in Guard Gate Mode!" << END << std::endl;
    }
    else
    {
        std::cout << B_GREEN << "ScavTrap " << this->name << " can't guard itself because it is dead!" << END << std::endl; 
    }
}


