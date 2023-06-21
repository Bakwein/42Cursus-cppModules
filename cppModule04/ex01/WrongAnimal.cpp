/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stunca <stunca@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 16:36:58 by stunca            #+#    #+#             */
/*   Updated: 2023/06/03 16:36:58 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

// Default constructor
WrongAnimal::WrongAnimal() : _type("WrongAnimal")
{
    std::cout << "WrongAnimal default constructor called" << std::endl;
}

// Copy constructor
WrongAnimal::WrongAnimal(WrongAnimal const& src)
{
    std::cout << "WrongAnimal copy constructor called" << std::endl;
    *this = src;
}

// Copy assignment operator
WrongAnimal& WrongAnimal::operator=(WrongAnimal const& wanimal)
{
    std::cout << "WrongAnimal copy assignment operator called" << std::endl;
    _type = wanimal.getType();
    return *this;
}

// Destructor
WrongAnimal::~WrongAnimal() { std::cout << "WrongAnimal destructor called" << std::endl; }

// Getter
std::string const& WrongAnimal::getType() const { return _type; }

// Setter
void WrongAnimal::setType(const std::string& type) { _type = type; }

// Public method
void WrongAnimal::makeSound() const { std::cout << "???" << std::endl; }