#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

int main()
{
    ClapTrap c1;
    ScavTrap s1;


    ClapTrap ct1("sefa"); // 10-10-0
    ScavTrap st1("tunca"); // 100-50-20

    ct1.setDamage(10);
    ct1.setHitPoint(50);

    st1.setDamage(25);

    ct1.attack("tunca");
    st1.takeDamage(ct1.getDamage());

    st1.ScavTrap::attack("sefa");
    ct1.takeDamage(st1.getDamage());

    st1.beRepaired(10);

    ScavTrap st2("robot");
    st2.guardGate();
    st1.attack("robot");
    st2.takeDamage(s1.getDamage());
    st1.ScavTrap::attack("sefa");
    st2.takeDamage(s1.getDamage());
    st1.ClapTrap::attack("sefa");
    st2.takeDamage(s1.getDamage());

    std::cout << "Destructors " << std::endl;




}