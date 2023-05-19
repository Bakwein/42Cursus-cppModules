/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stunca <stunca@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 19:51:24 by stunca            #+#    #+#             */
/*   Updated: 2023/05/19 19:51:28 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A_H
#define HUMAN_A_H

#include "Weapon.hpp"

class HumanA
{
    std::string name;
    Weapon &w; //ref olarak aldigimizdan neyi alıyorsak aldığımızı ve artık orada olmadığını düşünürüz
    public:
        HumanA(std::string name, Weapon &w);
        ~HumanA();
        void attack();
};

#endif