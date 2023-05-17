#include "Weapon.hpp"

Weapon::Weapon()
{

}

Weapon::Weapon(std::string type)
{
    this->type = type;

}

Weapon::~Weapon()
{
    std::cout << PURPLE <<this->getType() << " is destroyed" <<  END <<std::endl;
}

const std::string &Weapon::getType(void){return this->type;}
void Weapon::setType(std::string type){this->type=type;}
