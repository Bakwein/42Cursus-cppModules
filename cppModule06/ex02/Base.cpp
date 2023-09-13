#include "Base.hpp"

Base::~Base(void)
{
    std::cout << "Base's destructor." << std::endl;
}
/*
A::~A(void)
{
    std::cout << "A's destructor." << std::endl;
}

B::~B(void)
{
    std::cout << "B's destructor." << std::endl;
}

C::~C(void)
{
    std::cout << "C's destructor." << std::endl;
}
*/




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