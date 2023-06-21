/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stunca <stunca@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 16:37:24 by stunca            #+#    #+#             */
/*   Updated: 2023/06/03 16:37:24 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class AAnimal 
{
 protected:
  std::string _type;

 public:
  /* default constructor */
  AAnimal();

  /* copy constructor */
  AAnimal(AAnimal const& src);

  /* copy assignment operator */
  virtual AAnimal& operator=(AAnimal const& animal);

  /* destructor */
  virtual ~AAnimal();

  /* getter */
  std::string const& getType() const;

  virtual void makeSound() const = 0; //abstract
};

#endif