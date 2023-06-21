/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stunca <stunca@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 16:36:04 by stunca            #+#    #+#             */
/*   Updated: 2023/06/03 16:36:04 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

// Default constructor
Animal::Animal() : _type("Animal")
{
    std::cout << "Animal default constructor called" << std::endl;
}

// Copy constructor
Animal::Animal(Animal const& src)
{
    std::cout << "Animal copy constructor called" << std::endl;
    *this = src;
}

// Copy assignment operator
Animal& Animal::operator=(Animal const& animal)
{
    std::cout << "Animal copy assignment operator called" << std::endl;
    _type = animal.getType();
    return *this;
}

// Destructor
Animal::~Animal() { std::cout << "Animal destructor called" << std::endl; }

// Getter
std::string const& Animal::getType() const { return _type; }
std::string const& Animal::getIdea(int i) const { (void)i; return _type; }

// Public method
void Animal::makeSound() const { std::cout << "???" << std::endl; }

void Animal::printIdeas() const { std::cout << "???" << std::endl; }

