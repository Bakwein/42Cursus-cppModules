#include "ClapTrap.hpp"

int main()
{
    // DEFAULT
    //HIT POINT -> 10
    // ENERGY POINT -> 10
    // ATTACK DAMAGE -> 0
    ClapTrap ct1("Sefa");
    ClapTrap ct2("Tunca");

    ct1.setDamage(10);
    //ct2.beRepaired(20);
    ct2.godMode();
    ct1.attack(ct2.getName());
    ct2.takeDamage(200);
    ct1.setDamage(ct2.getHitPoint());
    ct1.attack(ct2.getName());
    ct1.takeDamage(ct1.getHitPoint());
    ct1.attack("robot");
    
    ClapTrap ct3("xd");
    ct3.setEnergy(1);
    ct3.attack("xd2");
    ct3.attack("xd2");
    

}