#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{

    if(argc == 2)
    {
        
        std::cout << "atoi: " <<ScalarConverter::atoi(argv[1]) << std::endl; 
    }
    else
    {
        std::cout << "argc must be 2!" << std::endl;
    }
}