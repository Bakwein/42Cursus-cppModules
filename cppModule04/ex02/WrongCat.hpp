/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stunca <stunca@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 16:39:13 by stunca            #+#    #+#             */
/*   Updated: 2023/06/03 16:39:13 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"
#include <iostream>
#include <string>

class WrongCat : public WrongAnimal
{
protected:
    std::string _type;
public:
    WrongCat();

    WrongCat(WrongCat const& src);

    WrongCat& operator=(WrongCat const& wcat);

    ~WrongCat();

    std::string const& getType() const;

    void makeSound() const;
};

#endif