#include "Zombie.hpp"

int main()
{
    /*
    //HEAP
    Zombie *z1 = newZombie("sefa");
    z1->announce();
    Zombie *z2 = newZombie("zombicik");
    z2->announce();

    //STACK
    randomChump("zom1");
    randomChump("zom2");
    

    Zombie z5("zom3");
    z5.announce();
    delete(z1);
    delete(z2);
    */


   std::string input,name;
   while(1)
   {
    std::cout << GREEN <<"If you wanna create a zombie for HEAP -> Type:1" << std::endl;
    std::cout << "If you wanna create a zombie for STACK -> Type:2" << std::endl;
    std::cout << "If you wanna exit-> Type 0"<<std::endl;
    std::cout << "➡";
    std::getline(std::cin,input);
    std::cout << END;
    if(!input.compare("0"))
    {
        std::cout<< RED<<"Exit input detected! See YOU 💘" << END <<std::endl; 
        break;
    }
    else if(!input.compare("1"))
    {
        std::cout << BLUE <<"HEAP" << END << std::endl;
        std::cout << PURPLE << "Enter a name:";
        std::getline(std::cin, name);
        Zombie* x = newZombie(name);
        x->announce();
        delete x;
        std::cout << END;
    }
    else if(!input.compare("2"))
    {
        std::cout << BLUE <<"STACK" <<  END<<std::endl;
        std::cout << PURPLE <<"Enter a name:";
        std::getline(std::cin, name);
        randomChump(name);
        std::cout << END;
    }
    else
    {
        std::cout<< RED<<"You enter wrong command!(Please use 0,1 or 2)" << END <<std::endl; 
    }
   }

    return 0;
}