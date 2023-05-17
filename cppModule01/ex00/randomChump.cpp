#include "Zombie.hpp"

// CREATING RANDOM ZOMBIE
void randomChump(std::string name)
{
    Zombie random(name);
    random.announce();
}