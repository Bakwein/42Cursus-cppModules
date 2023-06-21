/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stunca <stunca@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 16:35:34 by stunca            #+#    #+#             */
/*   Updated: 2023/06/03 16:35:34 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// Default constructor
Dog::Dog()
{
    std::cout << "Dog default constructor called" << std::endl;
    _type = "Dog";
}

// Copy constructor
Dog::Dog(Dog const& src) : Animal(src)
{
    std::cout << "Cat copy constructor called" << std::endl;
}

// Copy assignment operator
Dog& Dog::operator=(Dog const& dog)
{
    std::cout << "Cat copy assignment operator called" << std::endl;
    Animal::operator=(dog);
    return *this;
}

// Destructor
Dog::~Dog() { std::cout << "Dog destructor called" << std::endl; }

// Public method
void Dog::makeSound() const { std::cout << "Hav!" << std::endl; }
