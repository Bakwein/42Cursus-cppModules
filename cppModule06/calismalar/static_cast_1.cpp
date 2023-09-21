#include <iostream>

class Base {
public:
  virtual void foo() = 0;
};

class Derived : public Base {
public:
  void foo() 
  {
    std::cout << "Heyoo!!" << std::endl;
  }
};

int main()
{
  {
    double dd1 = 7.21;
    double dd2 = 15.12;
    double dd3;

    dd3 = (int)dd1 + dd2;
    std::cout << "dd3 değişken değeri: " << dd3 <<  "\n";

    dd3 = static_cast<int>(dd1) + dd2;
    std::cout << "dd3 değişken değeri: " << dd3 << "\n";

    std::cout << "\n";

    const char* str = "Hello, world!";
    std::string s = static_cast<std::string>(str);
    std::cout << s << std::endl; // Hello, world!

    int bes = 5;
    int* intPtr = &bes;
    void* voidPtr = static_cast<void*>(intPtr);
    int *tmp = (int*)voidPtr;
    std::cout << *tmp << std::endl;

    /*
    char c = 'a';
    int *p = static_cast<int*>(&c);
    HATAAAA
    */

    Derived d;
    Base* b = &d;
    Base* b2 = static_cast<Derived*>(b);
    b2->foo(); // Derived::foo()


    double d1 = static_cast<double>(-2);
    std::cout << "d1: " << d1 << std::endl;

    double f1 = static_cast<float>(-2);
    std::cout << "f1: " << f1 << std::endl;
  }
  
}