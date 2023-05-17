#include "HumanB.hpp"

HumanB::HumanB(std::string name):name(name)
{
    std::cout << GREEN<<this->name << " is ready to fight!" << END << std::endl;
}

HumanB::~HumanB()
{
    std::cout << RED <<  name << " is destroyed!"<< END << std::endl;
}

void HumanB::attack()
{
    std::cout << YELLOW << this->name << " attacks with their " << this->w->getType() << END <<std::endl;
}

void HumanB::setWeapon(Weapon &w)
{
    this->w = &w;
}
