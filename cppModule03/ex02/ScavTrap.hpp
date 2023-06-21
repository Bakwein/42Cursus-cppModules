/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stunca <stunca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:27:35 by stunca            #+#    #+#             */
/*   Updated: 2023/05/31 13:28:14 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    public:
        bool isGuardOn;

        ScavTrap(void);
        ScavTrap(std::string);
        ScavTrap(const ScavTrap &);
        ~ScavTrap();
        ScavTrap &operator=(const ScavTrap &);

        void    attack(const std::string &target);
        void    takeDamage(unsigned int);
        void    guardGate(void);
        unsigned int    getDemage(void);
};

#endif