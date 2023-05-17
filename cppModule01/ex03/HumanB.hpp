#ifndef HUMAN_B_H
#define HUMAN_B_H

#include "Weapon.hpp"

class HumanB
{
    std::string name;
    Weapon *w; 
    public:
        HumanB(std::string name);
        ~HumanB();
        void attack();
        void setWeapon(Weapon &w);
};

#endif