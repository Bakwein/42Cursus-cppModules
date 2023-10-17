#include "RPN.hpp"
#include <iostream>

RPN::RPN()
{
    //std::cout << "Default const. called" << std::endl;
}

RPN::RPN(RPN const &other)
{
    //std::cout << "Copy const. called" << std::endl;
    *this = other;
}

RPN::~RPN()
{
    //std::cout << "Destructor called" << std::endl;
}

RPN &RPN::operator=(RPN const &other)
{
    std::cout << "Assignation operator called" << std::endl;
    if (this != &other)
    {
        this->_stack = other._stack;
    }
    return (*this);
}

RPN::RPN(std::string const &str)
{
    for(size_t i = 0; i < str.size() ; i++)
    {
        if(str[i] == ' ')
            continue;
        if(str[i] >= '0' && str[i] <= '9')
            _stack.push(str[i] - '0');
        else if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
        {
            if(_stack.size() < 2)
                throw RPN::syntaxError();
            int a = _stack.top();
            _stack.pop();
            int b = _stack.top();
            _stack.pop();
            if(str[i] == '+')
                _stack.push(a + b);
            else if(str[i] == '-')
                _stack.push(b - a);
            else if(str[i] == '*')
                _stack.push(a * b);
            else if(str[i] == '/')
                _stack.push(b / a);
        }
        else
            throw RPN::syntaxError();
    }
    if(_stack.size() != 1)
            throw RPN::syntaxError();
    std::cout << _stack.top() << std::endl;
}



