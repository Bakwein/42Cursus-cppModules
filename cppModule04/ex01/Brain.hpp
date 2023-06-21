/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stunca <stunca@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 16:36:14 by stunca            #+#    #+#             */
/*   Updated: 2023/06/03 16:36:14 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <iostream>

class Brain
{
private:
    std::string _ideas[100];
public:
    Brain();
    Brain(Brain const& src);
    ~Brain();
    Brain& operator=(Brain const& brain);

    /* Getter */
    std::string const& getIdea(int index) const;

    /* Setter */
    void setIdea(int index, std::string const& idea);
};

#endif