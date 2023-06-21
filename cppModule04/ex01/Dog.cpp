/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stunca <stunca@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 16:36:25 by stunca            #+#    #+#             */
/*   Updated: 2023/06/03 16:36:25 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/* Default constructor */
Dog::Dog()
{
    std::cout << "Dog default constructor called" << std::endl;
    _type = "Dog";
    _brain = new Brain;
    for(int i = 0; i < 100; i++)
        setIdea(i, "");
}

/* Copy constructor */
Dog::Dog(Dog const& src) : Animal(src)
{
    std::cout << "Cat copy constructor called" << std::endl;
    _brain = new Brain;
    *_brain = *src._brain;
}

/* Copy assignment operator */
Dog& Dog::operator=(Dog const& dog)
{
    std::cout << "Cat copy assignment operator called" << std::endl;
    Animal::operator=(dog);
    *_brain = *dog._brain;
    return *this;
}

/* Destructor */
Dog::~Dog() { std::cout << "Dog destructor called" << std::endl; delete _brain; } // delete sebebi cat'deki ile aynı

/* Getters */
std::string const& Dog::getIdea(int i) const { return _brain->getIdea(i); }

/* Setter */
void Dog::setIdea(int i, std::string const& idea) { _brain->setIdea(i, idea); }

/* Public method */ 
void Dog::makeSound() const { std::cout << "Woof!" << std::endl; }

void Dog::printIdeas() const
{
    for(int i = 0; i < 100; i++)
    {
        if(getIdea(i) != "")
            std::cout << i << ". Idea: "<< getIdea(i) << std::endl;
    }
}