/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stunca <stunca@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 16:39:05 by stunca            #+#    #+#             */
/*   Updated: 2023/06/03 16:39:05 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

// Default constructor
WrongCat::WrongCat()
{
    std::cout << "WrongCat default constructor called" << std::endl;
    this->setType("WrongCat");
}

// Copy constructor
WrongCat::WrongCat(WrongCat const& src) : WrongAnimal(src) 
{
    std::cout << "WrongCat copy constructor called" << std::endl;
    *this = src;
}

// Copy assignment operator
WrongCat& WrongCat::operator=(WrongCat const& wcat)
{
    std::cout << "WrongCat copy assignment operator called" << std::endl;
    WrongAnimal::operator=(wcat);
    return *this;
}

// Destructor
WrongCat::~WrongCat() { std::cout << "WrongCat destructor called" << std::endl; }

// Getter
std::string const& WrongCat::getType() const { return _type; }

// Public method
void WrongCat::makeSound() const { std::cout << "Meow" << std::endl; }