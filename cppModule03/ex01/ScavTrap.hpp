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