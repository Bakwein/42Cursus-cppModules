#ifndef RPN_H
#define RPN_H

#include <stack>

class RPN
{
    private:
        std::stack<int> _stack;
    public:
        RPN();
        RPN(RPN const &other);
        ~RPN();
        RPN &operator=(RPN const &other);
        RPN(std::string const &str);


        //exceptions
        class argcError : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return ("Error : argc must be 2");
                }
        };

        class syntaxError : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return ("Error");
                }
        };

        

};

#endif