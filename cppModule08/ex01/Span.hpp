#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>

class Span
{
    private:
        std::vector<int> vec;
        unsigned int N;
        Span();
    public:
        Span(unsigned int n);
        Span(const Span &rhs);
        ~Span();
        Span& operator=(Span const& rhs);

        void printVector(void)const;
        void addNumber(int num);
        void addNumber(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end);
        long int shortestSpan()const;
        long int longestSpan()const;

        void editValue(unsigned int index, int value);

        unsigned int getN()const;
        void setN(unsigned int n);

        std::vector<int> getVec()const;

};

#endif