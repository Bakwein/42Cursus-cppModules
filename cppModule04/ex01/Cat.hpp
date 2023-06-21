/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stunca <stunca@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 16:36:22 by stunca            #+#    #+#             */
/*   Updated: 2023/06/03 16:36:22 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
  Brain* _brain;
public:
    /* default constructor */
    Cat();

    /* copy constructor */
    Cat(Cat const& src);

    /* copy assignment operator */
    Cat& operator=(Cat const& cat);

    /* destructor */
    virtual ~Cat();

    /* getters */
    std::string const& getIdea(int i) const;    

    /* setter */
    void setIdea(int i, std::string const& idea);

    /* public methods */
    void printIdeas() const;
    virtual void makeSound() const;
};

#endif