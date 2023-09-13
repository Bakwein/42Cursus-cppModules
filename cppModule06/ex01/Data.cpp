#include "Data.hpp"

//It takes a pointer and converts it to the unsigned integer type uintptr_t.
uintptr_t serialize(Data* ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}

//It takes an unsigned integer parameter and converts it to a pointer to Data.
Data* deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data*>(raw));
}

/*
uintptr_t, C++'da bir adresin değerini depolamak için kullanılan bir türdür. Bir pointer'ın değerini bir integer'a dönüştürmek için kullanılır. Bu, pointer'ları daha kolay karşılaştırmak ve işlemek için kullanılabilir.

uintptr_t, C++11 standartlarında tanıtıldı ve C99 standartlarında da mevcuttur.

uintptr_t'nin bazı kullanımları şunlardır:

Pointer'ları daha kolay karşılaştırmak ve işlemek için.
Pointer'ları bir fonksiyona parametre olarak geçirmek için.
Pointer'ları bir veri yapısında depolamak için.
*/

/*
reinterpret_cast<veri_türü>(ifade)
bir veri türünü tamamen farklı bir veri türüne dönüştürür.
reinterpret_cast operatörü yalnızca işaretçiler veya tamsayılar arasında dönüştürmek için kullanılabilir.
double x_ = 43.2;
double *x1 = &x_;
double *s = reinterpret_cast<double*>(x1);
std::cout << *s << std::endl;

int sefa = 4;
int *p_sefa = &sefa;
int last = reinterpret_cast<int>(*p_sefa);
std::cout << last << std::endl;

*/

/*
The reinterpret_cast is a type casting operator in C++ that can be used to convert a pointer of one data type to a pointer of another data type, even if the data types before and after conversion are different.
The reinterpret_cast is a very powerful operator, but it is also very dangerous. It can be used to create invalid pointers, which can lead to undefined behavior. Therefore, the reinterpret_cast should only be used when absolutely necessary.
The syntax for the reinterpret_cast is:
reinterpret_cast<new_type>(expression)
where new_type is the new data type of the pointer and expression is the expression that evaluates to a pointer.

For example, the following code converts a pointer to an int to a pointer to a char:

int *p_int = new int(10);
char *p_char = reinterpret_cast<char *>(p_int);
This code is safe because the size of an int is the same as the size of a char. However, the following code is unsafe because the size of a double is different from the size of an int:

int *p_int = new int(10);
double *p_double = reinterpret_cast<double *>(p_int);
This code could create an invalid pointer to a memory location that is not allocated for a double.

The reinterpret_cast should only be used when absolutely necessary. It should not be used to convert between pointers of different types unless the sizes of the types are the same.

Here are some of the cases where the reinterpret_cast can be used safely:

To convert between pointers and their numerical (integer) values.
To convert between pointers to different data types that have the same size.
To access the raw bytes of an object.
Here are some of the cases where the reinterpret_cast should not be used:

To convert between pointers of different types that have different sizes.
To create a pointer to an object that is not allocated.
To cast away const or volatile qualifiers.
The reinterpret_cast is a powerful tool, but it should be used with caution.

*/

/*
Here are some of the reasons why we might use reinterpret_cast:

To convert between pointers and their numerical (integer) values. For example, we might use reinterpret_cast to convert a pointer to an integer so that we can pass it as an argument to a function that expects an integer.
To convert between pointers to different data types that have the same size. For example, we might use reinterpret_cast to convert a pointer to a char to a pointer to an int if we are only interested in the raw bytes of the object.
To access the raw bytes of an object. For example, we might use reinterpret_cast to access the raw bytes of a memory buffer so that we can write or read data to it.

Here are some of the cases where we should not use reinterpret_cast:

To convert between pointers of different types that have different sizes. This could create an invalid pointer to a memory location that is not allocated for the new type.
To create a pointer to an object that is not allocated. This could lead to undefined behavior.
To cast away const or volatile qualifiers. This could make the object accessible in ways that it was not intended to be accessed.

*/