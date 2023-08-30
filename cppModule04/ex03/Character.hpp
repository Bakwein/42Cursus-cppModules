#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
    private:
        std::string name;
        AMateria *inv[4];
    public:
        Character(void);
        Character(std::string const &name);
        Character(Character const &rhs);
        ~Character(void);

        Character &operator=(Character const &rhs);

        std::string const &getName()const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
};

#endif