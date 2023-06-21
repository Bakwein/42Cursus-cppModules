/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stunca <stunca@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 16:35:28 by stunca            #+#    #+#             */
/*   Updated: 2023/06/03 16:35:28 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// Default constructor
Cat::Cat()
{
    std::cout << "Cat default constructor called" << std::endl;
    _type = "Cat";
}

// Copy constructor
Cat::Cat(Cat const& src) : Animal(src)
{
    std::cout << "Cat copy constructor called" << std::endl;
}

// Copy assignment operator
Cat& Cat::operator=(Cat const& cat)
{
    std::cout << "Cat copy assignment operator called" << std::endl;
    Animal::operator=(cat);
    return *this;
}

// Destructor
Cat::~Cat() { std::cout << "Cat destructor called" << std::endl; }

// Public method
void Cat::makeSound() const { std::cout << "Meow" << std::endl; }