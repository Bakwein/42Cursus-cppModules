#include "Array.hpp"

template <typename T>
Array<T>::Array() : size(0)
{
    std::cout << "Default const." << std::endl;
    ptr = new T[size];
}   

template <typename S>
Array<S>::Array(unsigned int n) : size(n)
{
    std::cout << "unsig. int const." << std::endl;
    ptr = new S[size];
}

template <typename M>
Array<M>::Array(const Array &a) : size(a.getSize())
{
    std::cout << "Copy const." << std::endl;
    ptr = NULL;
    *this = a;
}

template <typename B>
Array<B>& Array<B>::operator=(const Array<B> &a)
{
    if(this->ptr != NULL)
        delete [] this->ptr;
    if(a.size() != 0)
    {
        this->size = a.getSize();
        ptr = new B[size];
        for(unsigned int i = 0; i < size ; i++)
        {
            ptr[a] = a[i];
        }
    }
}

template <typename E>
Array<E>& Array<E>::operator[](unsigned int index)
{
    if(index >= size || ptr == NULL || 0 > index)
        throw std::exception();
    return(ptr[index]);
}


template <typename T>
unsigned int Array<T>::getSize(){return size;}

template<typename T>
void Array<T>::setSize(unsigned int size){this->size = size;}