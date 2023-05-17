#include "Harl.hpp"

int main(int argc,char **argv)
{
    if(argc == 2)
    {
        Harl h;
        h.complain(argv[1]);
    }
    else
    {
        std::cout << "argc must be 2. ./harlFilter <things> " << std::endl;
    }
    return 0;
}