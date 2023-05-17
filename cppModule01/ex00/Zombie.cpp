#include "Zombie.hpp"

// ZOMBIE IN STACK

Zombie::Zombie(std::string Name)
{
    this->Name = Name;
}

Zombie::~Zombie()
{
    std::cout << "Zombie(" << this->Name << ") has been destroyed." << std::endl;
}

void Zombie::announce(void)
{
    std::cout << this->Name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}