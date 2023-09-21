#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base(void)
{
    std::cout << "Base's destructor." << std::endl;
}


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
    std::cout << BLUE << "num: " << num << RESET << std::endl;
    if(num == 0)
    {
        std::cout << PURPLE <<"A is being created." << RESET <<std::endl;
        return (makeA());
    }
    else if(num == 1)
    {
        std::cout << PURPLE <<"B is being created." << RESET << std::endl;
        return (makeB());
    }
    else
    {
        std::cout << PURPLE << "C is being created." << RESET << std::endl;
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
        std::cout<< GREEN << "Class is A" << RESET << std::endl;
    }
    else
    {
        std::cout << RED << "Class is not A" << RESET << std::endl;
    }

    if(b_ptr != NULL)
    {
        std::cout<< GREEN << "Class is B" << RESET  << std::endl;
    }
    else
    {
        std::cout << RED << "Class is not B" << RESET <<std::endl;
    }

    if(c_ptr != NULL)
    {
        std::cout<< GREEN << "Class is C" << RESET << std::endl;
    }
    else
    {
        std::cout << RED << "Class is not C" << RESET << std::endl;
    }

}

void identify(Base& p)
{
    try
    {
        A &a_ref = dynamic_cast<A&>(p);
        (void)a_ref;
        std::cout << GREEN << "Class A" << RESET << std::endl;
    }
    catch(const std::bad_cast& e)
    {
        std::cout << RED<< e.what() <<RESET << std::endl;
    }
    catch(const std::exception& e1)
    {
        std::cout << e1.what() << std::endl;
    }


    try
    {
        B &b_ref = dynamic_cast<B&>(p);
        (void)b_ref;
        std::cout << GREEN << "Class B" << RESET << std::endl;
    }
    catch(const std::exception& e2)
    {
        std::cout<< RED << e2.what() << RESET << std::endl;
    }
    
    try
    {
        C &c_ref = dynamic_cast<C&>(p);
        (void)c_ref;
        std::cout << GREEN << "Class C" << RESET << std::endl;
    }
    catch(const std::exception& e3)
    {
        std::cout << RED << e3.what() << RESET << 
     std::endl;
    }
    
    


}




/*
dynamic_cast<veri_türü>(ifade)
//dynamic_cast işlemicisi, bir veri türündeki işaretçinin diğer bir veri türüne,bir veri türündeki referansın da veri türüne çevrilmesini sağlar
//esas amaç,bir ana sınıf ve bu sınıftan türetilmiş sınıflardan oluşan herhangi bir nesnenin adresini gösterebileceğinden, dynamic_cast işlemcisi türetilmiş sınıf işaretcisini ana sınıf işaretçisine dönüştürebilir.Ancak dynamic_cast işlemcisi,sadece gösterilen nesne bir türetilmiş sınıf nesnesi ise , bir ana sınıf işaretçisinin türetilmiş sınıf işaretçesine dönüştürebilir.
// Dönüştürülecek olan işaretçi veya referans, hedef veri türünden bir nesne veya hedef veri türünden türetilen bir nesne ise dynamic_cast başarıyla sonuçlanır.
// Dönüştürme başarısız olduğunda işlem işaretçi ile yapılıyorsa NULL, referans ile yapılıyorsa bad_cast hata sonucu elde edilir
*/

/*
The dynamic_cast operator in C++ is used to cast a pointer or reference of a polymorphic type to another type. Polymorphic types are types that can have derived classes. The dynamic_cast operator performs a run-time type check to ensure that the cast is valid.

The syntax for the dynamic_cast is:

dynamic_cast<target_type>(expression)
where target_type is the type to which the pointer or reference is being cast and expression is the expression that evaluates to a pointer or reference.

For example, the following code casts a pointer to a Base class to a pointer to a Derived class:

Base *base_ptr = new Derived();
Derived *derived_ptr = dynamic_cast<Derived *>(base_ptr);
If base_ptr is actually pointing to a Derived object, then the dynamic_cast operator will succeed and derived_ptr will be a valid pointer to the Derived object. If base_ptr is not pointing to a Derived object, then the dynamic_cast operator will fail and derived_ptr will be a null pointer.

The dynamic_cast operator can also be used to cast a reference to a polymorphic type. For example, the following code casts a reference to a Base class to a reference to a Derived class:

Base &base_ref = *base_ptr;
Derived &derived_ref = dynamic_cast<Derived &>(base_ref);
If base_ref is actually referring to a Derived object, then the dynamic_cast operator will succeed and derived_ref will be a valid reference to the Derived object. If base_ref is not referring to a Derived object, then the dynamic_cast operator will fail and derived_ref will be undefined.

The dynamic_cast operator is a powerful tool that can be used to perform safe downcasting at run time. However, it is important to use it carefully. If the cast fails, the dynamic_cast operator will return a null pointer or an undefined reference. This can lead to undefined behavior if the program does not handle the failure gracefully.

Here are some of the things to keep in mind when using dynamic_cast:

The dynamic_cast operator only works for polymorphic types.
The dynamic_cast operator performs a run-time type check. This can have a performance impact.
The dynamic_cast operator can fail if the cast is not valid.
The dynamic_cast operator can return a null pointer or an undefined reference if the cast fails.
The dynamic_cast operator is a valuable tool for performing safe downcasting at run time. However, it is important to use it carefully and to understand the risks involved.
*/