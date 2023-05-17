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