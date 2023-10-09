#include "Span.hpp"
#include <iostream>

Span::Span(unsigned int n) : N(n)
{
    std::cout << "span(int) const. called" << std::endl;
}

Span::Span(const Span &rhs)
{
    //std::cout << "Span copy const. called" << std::endl;
    *this = rhs;
}

Span::~Span()
{
    std::cout << "Span destructor called" << std::endl;
}

Span& Span::operator=(Span const& rhs)
{
    //std::cout << "Span copy assignment called" << std::endl;
    this->vec = rhs.getVec();
    this->N = rhs.getN();
    return *this;
}

void Span::printVector()const
{
    std::vector<int>::const_iterator i1;
    for(i1 = this->vec.cbegin(); i1 != this->vec.cend();i1++)
    {
        std::cout << *i1 << " ";
    }
    std::cout << std::endl;
}

void Span::addNumber(int num)
{
    if(this->N == this->vec.size())
        throw std::out_of_range("Vector is full!");
    this->vec.push_back(num);
}

/*
C++'da std::distance() işlevi, iki iteratör arasındaki mesafeyi hesaplar. std::distance() işlevi, bir InputIterator türünden iki iteratör alır ve bunların arasındaki mesafeyi, bir difference_type türünden bir değer olarak döndürür.
*/
void Span::addNumber(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end)
{
    if(this->vec.size() + std::distance(begin,end) > this->N)
    {
        throw std::length_error("overflow detected!");
    }
    this->vec.insert(this->vec.end(),begin,end);
}

long int Span::shortestSpan()const
{
    if(this->vec.size() <= 1)
        throw std::length_error("there is not enough value for shortestSpan");
    long int ret = INT_MAX;
    std::vector<int> tmp = this->getVec();
    std::sort(tmp.begin(),tmp.end());
    for(std::vector<int>::const_iterator i1 = tmp.cbegin();i1+1 != tmp.cend();i1++)
    {
        long int s = *(i1 + 1) - *i1;
        if(s < ret)
            ret = s;
    }
    return ret;
}

/*
std::min_element() işlevi, bir dizideki en küçük elemanı döndürür. std::min_element() işlevi, bir ForwardIterator türünden iki iteratör alır ve bu iteratörlerin kapsadığı dizideki en küçük elemanı, bir ForwardIterator türünden bir iteratör olarak döndürür.

C++'da std::max_element() işlevi, bir dizideki en büyük elemanı döndürür. std::max_element() işlevi, bir ForwardIterator türünden iki iteratör alır ve bu iteratörlerin kapsadığı dizideki en büyük elemanı, bir ForwardIterator türünden bir iteratör olarak döndürür.
*/
long int Span::longestSpan()const
{
    if(this->vec.size() <= 1)
        throw std::length_error("there is not enough value for longestSpan");
    long int min_span = *std::min_element(this->vec.begin(),this->vec.end());
    long int max_span = *std::max_element(this->vec.begin(),this->vec.end());
    return(max_span - min_span);
}



void Span::editValue(unsigned int index,int value)
{
    if(index < 0 || index >= N)
    {
        throw std::out_of_range("index is out of range!");
    }
    vec.at(index) = value;
    std::cout << "vec[" << index << "]: " << value << std::endl;
}

unsigned int Span::getN()const{return N;}
void Span::setN(unsigned int n){this->N = n;}

std::vector<int> Span::getVec()const{return this->vec;}