#include <iostream>
#include <string>

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

  /*
    std::cout << "---------------------------" << std::endl;
    std::cout << static_cast<int>(+3.) << std::endl;
    std::cout << typeid(3.f).name() << std::endl;

    std::cout << "\n";

    std::cout << static_cast<int>(00032.) << std::endl;
    std::cout << typeid(00032.).name() << std::endl;
    
    std::cout << "\n";
    std::cout << static_cast<int>(00032) << std::endl;
    std::cout << typeid(00032).name() << std::endl;
    
    std::cout << "\n";
    std::cout << static_cast<int>(00000) << std::endl;
    std::cout << typeid(00000).name() << std::endl;
    
    std::cout << "\n*";
    std::cout << static_cast<int>(+00000000000000000000000000000) << std::endl;
    std::cout << typeid(+00000000000000000000000000000).name() << std::endl;
    std::cout << static_cast<int>(-00000000000000000000000000000) << std::endl;
    std::cout << typeid(-00000000000000000000000000000).name() << std::endl;
    std::cout << static_cast<int>(00000000000000000000000000000) << std::endl;
    std::cout << typeid(00000000000000000000000000000).name() << std::endl;

    std::cout << "\n";
    std::cout << static_cast<int>(000000000000000000000000000001) << std::endl;
    std::cout << typeid(000000000000000000000000000001).name() << std::endl;

    std::cout << "\n";
    std::cout << static_cast<int>(1872648712647816287461287.f) << std::endl;
    std::cout << typeid(1872648712647816287461287.f).name() << std::endl;

    std::cout << "\n";
    //std::cout << static_cast<double>(1872648712647816287461287) << std::endl;
    //std::cout << typeid(1872648712647816287461287).name() << std::endl;

    std::cout << "\n";
    std::cout << static_cast<float>( 1.25125e+13) << std::endl;
    std::cout << typeid( 1.25125e+13).name() << std::endl;

    std::cout << "\n";
    std::cout << int(2147483648.2) << std::endl;

  //2147483649
    std::cout << "\n";
    std::cout << static_cast<float>( -2147483649) << std::endl;
    std::cout << typeid(2147483649).name() << std::endl;


    std::cout << "\n*";
    std::cout << static_cast<int>(std::stof("nan")) << std::endl;
    std::cout << static_cast<int>(std::stof("nanf")) << std::endl;

    std::cout << "\n*";
    std::cout << static_cast<int>(std::stof("inf")) << std::endl;
    std::cout << static_cast<int>(std::stof("inff")) << std::endl;

    //124124f
    std::cout << "\n";
    std::string xd = "asdhasdh";
    std::cout << xd.find(".") << " " << int(xd.find(".")) << std::endl;
    */

   
  }
  
}