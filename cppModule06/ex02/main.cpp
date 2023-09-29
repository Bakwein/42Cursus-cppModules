#include "Base.hpp"


int main()
{

    srand(time(NULL));
    Base b;

    Base *ptr1 = generate();
    
    Base *ptr2 = generate();
    
    std::cout << "---------------------\n";

    identify(ptr1);
    std::cout << "\n";
    identify(ptr2);
    std::cout << "\n";
    identify(*ptr1);
    std::cout << "\n";
    identify(*ptr2);


    std::cout << "---------------------\n";

    Base &ref1 = *ptr1;
    Base &ref2 = *ptr2;
    identify(ref1);
    std::cout << "\n";
    identify(ref2);

    delete ptr1;
    delete ptr2;

    return 0;

}