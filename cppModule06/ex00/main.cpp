#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    try
    {
        if(argc == 2)
        {
            std::string xd = argv[1];
            int index = xd.find(' ');
            while(index != -1)
            {
                xd.erase(index,1);
                index = xd.find(' ');
            }
            if(int(xd.length()) == 0)
            {
                std::cout << YELLOW << "String is empty!" << RESET << std::endl;
                return (0);
            }
            ScalarConverter::convert(xd);
        }
        else
        {
            std::cout << "argc must be 2!" << std::endl;
            exit(0);
        }
    }
    catch(const std::exception& e)
    {
        std::cout << "EXCEPTION FOUND :" << e.what() << "\n";
    }
    
    
}