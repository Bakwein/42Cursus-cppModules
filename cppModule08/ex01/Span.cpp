#include "Span.hpp"
#include <iostream>

Span::Span(unsigned int n) : N(n)
{
    std::cout << "span(int) dest. called" << std::endl;
}

Span::Span(const Span &rhs)
{
    std::cout << "Span copy const. called" << std::endl;
    *this = rhs;
}

Span& Span::operator=(Span const& rhs)
{
    
}