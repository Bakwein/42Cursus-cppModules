/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stunca <stunca@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 16:36:19 by stunca            #+#    #+#             */
/*   Updated: 2023/06/03 16:36:19 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/* Default constructor */ 
Cat::Cat()
{
    std::cout << "Cat default constructor called" << std::endl;
    _type = "Cat";
    _brain = new Brain;
    for(int i = 0;i < 100; i++)
        setIdea(i, "");
}

/* Copy constructor */
Cat::Cat(Cat const& src) : Animal(src)
{
    std::cout << "Cat copy constructor called" << std::endl;
    _brain = new Brain;
    *_brain = *src._brain;
}

/* Copy assignment operator */ 
Cat& Cat::operator=(Cat const& cat)
{
    std::cout << "Cat copy assignment operator called" << std::endl;
    Animal::operator=(cat);
    *_brain = *cat._brain;
    return *this;
}

/* Destructor */ 
Cat::~Cat() { std::cout << "Cat destructor called" << std::endl; delete _brain; } // delete sebebi oluşturduğumuz nesneyi leak vermemesi için kaldırmak

/* Getters */
std::string const& Cat::getIdea(int i) const { return _brain->getIdea(i); }

/* Setter */
void Cat::setIdea(int i, std::string const& idea) { _brain->setIdea(i, idea); }

/* Public method */ 
void Cat::makeSound() const { std::cout << "Meow" << std::endl; }

void Cat::printIdeas() const
{
    for(int i = 0; i < 100; i++)
    {
        if(getIdea(i) != "")
            std::cout << i << ". Idea: "<< getIdea(i) << std::endl;
    }
}