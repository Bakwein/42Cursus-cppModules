/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stunca <stunca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:27:02 by stunca            #+#    #+#             */
/*   Updated: 2023/05/31 13:27:03 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("default"),hitPoint(10),energyPoint(10),attackDamage(0)
{
    std::cout << BLUE << this->name << " is created with ClapTrap Default Constructor!" << END <<std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name),hitPoint(10), energyPoint(10), attackDamage(0)
{
    std::cout << BLUE <<this->name << " is created with String ClapTrap Constructor!" << END <<std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &old) : name(old.name) , hitPoint(old.hitPoint), energyPoint(old.energyPoint) , attackDamage(old.attackDamage)
{
    std::cout << BLUE <<  this->name << " is created with Copy ClapTrap Constructor!" << END <<std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << B_RED <<this->name << "is closed with ClapTrap Destructor!" << END <<  std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &c) 
{
    this->name = c.name;
    this->hitPoint = c.hitPoint;
    this->energyPoint = c.energyPoint;
    this->attackDamage = c.attackDamage;
    std::cout << CYAN << "ClapTrap Copy Assignment Opeator called: " << this->name << END << std::endl;
    return (*this);
}

bool ClapTrap::isAlive()
{
    if(this->hitPoint <= 0)
    {
        std::cout  << RED << "ClapTrap "<< this->name << " is already dead!" << END <<std::endl;
        return (false);    
    }
    else if(this->energyPoint <= 0)
    {
        std::cout << RED <<"ClapTrap "<<this->name << " has no energy point!" << END <<std::endl;
        return (false);
    }
    return (true);
}

// ClapTrap <name> attacks <target>, causing <damage> points of damage!
void ClapTrap::attack(const std::string &target)
{
    if(!(this->isAlive()))
        return ;
    std::cout << PURPLE <<"ClapTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << END <<std::endl;
    this->energyPoint--;
    std::cout << BLUE <<"Remaining energy point -> " << this->energyPoint << END << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if(!(this->isAlive()))
        return ;
    std::cout << PURPLE <<"ClapTrap " << this->name << " has taken " << amount << " damage!" << END << std::endl;
    if(amount > this->hitPoint)
    {
        this->hitPoint = 0;
        std::cout << RED <<"ClapTrap " << this->name << " is dead!" << END <<std::endl;
    }
    else
    {
        this->hitPoint -= amount;
    }
    std::cout << BLUE <<"ClapTrap " << this->name << " remaining hit point -> " << this->hitPoint <<  END <<std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if(!(this->isAlive()))
        return ;
    this->hitPoint += amount;
    std::cout << PURPLE <<"ClapTrap " << this->name << " repaired " << amount << " hit points!" << std::endl;
    std::cout << "Now ClapTrap " << this->name << " has " << this->hitPoint << " hit point!" << END << std::endl;
    this->energyPoint--;
    std::cout << BLUE << this->name << "\'s remaining energy point -> " << this->energyPoint << END << std::endl;
}

std::string ClapTrap::getName(){return this->name;}
void ClapTrap::setName(std::string name)
{
    std::cout << YELLOW << "Name changed!" << std::endl;
    std::cout << "Old name -> " << this->name << std::endl;
    this->name = name;
    std::cout << "New name -> " << this->name << END <<std::endl;
}

unsigned int ClapTrap::getHitPoint(){return this->hitPoint;}

void ClapTrap::setHitPoint(unsigned int hitPoint)
{
    std::cout << YELLOW << "Hit point changed!" << std::endl;
    std::cout << "Old hit point -> " << this->hitPoint << std::endl;
    this->hitPoint = hitPoint;
    std::cout << "New hit point -> " << this->hitPoint << END << std::endl;
}

void ClapTrap::setEnergy(unsigned int energy) 
{
    std::cout <<YELLOW <<this->name << " \'s energy changed!" << std::endl;
    std::cout << "Old energy -> " << this->energyPoint << std::endl;
    this->energyPoint = energy;
    std::cout << "New enerhy -> " << this->energyPoint<< END << std::endl;
}

void ClapTrap::setDamage(unsigned int damage)
{
    std::cout << YELLOW << this->name << " \'s Damage changed!" << std::endl;
    std::cout << "Old damage -> " << this->attackDamage << std::endl;
    this->attackDamage = damage;
    std::cout << "New damage -> " << this->attackDamage << END<< std::endl;
}

void ClapTrap::godMode()
{
    std::cout << B_BLUE << "GOD MODE activated for " << this->name <<  END <<std::endl;
    this->attackDamage = this->hitPoint = this->energyPoint =1000000;
}

unsigned int ClapTrap::getDamage()
{
    return (this->attackDamage);
}