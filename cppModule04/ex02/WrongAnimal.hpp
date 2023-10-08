/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stunca <stunca@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 16:39:01 by stunca            #+#    #+#             */
/*   Updated: 2023/06/03 16:39:01 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal
{
protected:
    std::string _type;
public:
    WrongAnimal();

    WrongAnimal(WrongAnimal const& src);

    WrongAnimal& operator=(WrongAnimal const& wanimal);

    ~WrongAnimal();

    void setType(const std::string& type);
    
    std::string const& getType() const;

    void makeSound() const;
};

#endif