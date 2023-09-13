#include "Base.hpp"

Base* makeA(void)
{
    return new A();
}

Base* makeB(void)
{
    return new B();
}

Base* makeC(void)
{
    return new C();
}

Base* generate(void)
{
    int num = rand() % 3;
    std::cout << "num: " << num << std::endl;
    if(num == 0)
    {
        return (makeA());
    }
    else if(num == 1)
    {
        return (makeB());
    }
    else
    {
        return (makeC());
    }
}

void identify(Base* p)
{
    A* a_ptr = dynamic_cast<A*>(p);
    B* b_ptr = dynamic_cast<B*>(p);
    C* c_ptr = dynamic_cast<C*>(p);

    if(a_ptr != NULL)
    {
        std::cout<< "Class is A" << std::endl;
    }
    else
    {
        std::cout << "Class is not A" << std::endl;
    }

    if(b_ptr != NULL)
    {
        std::cout<< "Class is B" << std::endl;
    }
    else
    {
        std::cout << "Class is not B" << std::endl;
    }

    if(c_ptr != NULL)
    {
        std::cout<< "Class is C" << std::endl;
    }
    else
    {
        std::cout << "Class is not C" << std::endl;
    }

}

void identify(Base& p)
{
    (void)p;
    std::cout << "YAPILACAK!!" << std::endl;
}


int main()
{

    srand(time(NULL));
    Base b;

    Base *ptr1 = generate();
    (void)ptr1;


}