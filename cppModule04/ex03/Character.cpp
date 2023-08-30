#include "Character.hpp"

Character::Character(void) : name("default")
{
    for(int i = 0; i < 4;i++)
        this->inv[i] = NULL;
}

Character::Character(std::string const &name) : name(name)
{
    for(int i = 0; i < 4;i++)
        this->inv[i] = NULL;
}

Character::Character(Character const &rhs) : name(rhs.getName())
{
    *this = rhs;
}

Character::~Character()
{
    for(int i = 0; i < 4 ; i++)
        delete inv[i];
}

Character &Character::operator=(Character const &rhs)
{
    if(this != &rhs)
    {
        this->name = rhs.getName();
        for(int i = 0; i < 4 ; i++)
        {
            this->inv[i] = rhs.inv[i];
        }
    }
    return (*this);
}

std::string const &Character::getName()const
{
    return (this->name);
}

void Character::equip(AMateria* m)
{
    for(int i = 0; i < 4 ; i++)
    {
        if(this->inv[i] == NULL)
        {
            this->inv[i] = m;
            return;
        }
    }
}

void Character::unequip(int idx)
{
    if(inv[idx] != NULL)
    {
        delete inv[idx];
        inv[idx] = NULL;
    }
}

void Character::use(int idx, ICharacter& target)
{
    if(this->inv[idx])
    {
        this->inv[idx]->use(target);
    }
}
