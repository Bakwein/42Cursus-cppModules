#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    if(N <= 0)
        return NULL;
    Zombie *zombieArray = new Zombie[N];
    for(int i = 0; i < N; i++)
    {
        zombieArray[i].setName(name);
    }
    return zombieArray;

}