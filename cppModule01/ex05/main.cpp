#include "Harl.hpp"

int main()
{
    Harl h1;
    std::string level; 

    while(1)
    {
        std::cout << CYAN <<  "Write DEBUG,INFO,WARNING,ERROR OR Q FOR QUIT"<< std::endl;
        std::cout << "➡";
        std::getline(std::cin,level);
        std::cout << END;
        if(!level.compare("Q"))
        {
            std::cout << RED << "Quit command detected!" << std::endl;
            break;
        }
        else if(!level.compare("DEBUG") || !level.compare("INFO") || !level.compare("WARNING") || !level.compare("ERROR"))
            h1.complain(level);
        else
        {
            std::cout << RED <<"Wrong input! Try DEBUG,INFO,WARNING,ERROR OR Q FOR QUIT" << END << std::endl;
        }
    }
return 0;
}