#ifndef MUTANT_STACK_TPP
#define MUTANT_STACK_TPP

#include "MutantStack.hpp"
#include <iostream>
//templatede class yerine typename ile dene

template <typename T,class container>
MutantStack<T,container>::MutantStack()
{
    std::cout << "default const. called" << std::endl;
}

template <typename T,class container>
MutantStack<T,container>::MutantStack(const MutantStack<T,container>& rhs)
{
    std::cout << "MutantStack copy const called" << std::endl;
    *this = rhs;
}

template <typename T,class container>
MutantStack<T,container>::~MutantStack()
{
    std::cout << "MutantStack destructor called" << std::endl;
}

template <typename T,class container>
MutantStack<T,container> &MutantStack<T,container>::operator=(MutantStack<T,container> const& obj)
{
    std::cout << "MutantStack copy assignment called!" << std::endl;
    std::stack<T,container>::operator=(obj);
    return(*this);
}

template<typename T,class container>
typename MutantStack<T,container>::iterator MutantStack<T,container>::begin()
{
    return this->c.begin();   
}

template<typename T,class container>
typename MutantStack<T,container>::iterator MutantStack<T,container>::end()
{
    return this->c.end();   
}

template<typename T,class container>
typename MutantStack<T,container>::const_iterator MutantStack<T,container>::cbegin()const
{
    return this->c.cbegin();   
}

template<typename T,class container>
typename MutantStack<T,container>::const_iterator MutantStack<T,container>::cend()const
{
    return this->c.cend();   
}

template<typename T,class container>
typename MutantStack<T,container>::reverse_iterator MutantStack<T,container>::rbegin()
{
    return this->c.rbegin();   
}

template<typename T,class container>
typename MutantStack<T,container>::reverse_iterator MutantStack<T,container>::rend()
{
    return this->c.rend();   
}

template<typename T,class container>
typename MutantStack<T,container>::const_reverse_iterator MutantStack<T,container>::crbegin()const
{
    return this->c.crbegin();   
}

template<typename T,class container>
typename MutantStack<T,container>::const_reverse_iterator MutantStack<T,container>::crend()const
{
    return this->c.crend();   
}



#endif