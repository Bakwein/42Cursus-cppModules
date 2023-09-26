#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
    private:
        T *ptr;
        unsigned int size;


    public:
        //
        Array();
        Array(unsigned int n);
        
        Array(const Array &a);
        Array &operator=(const Array &a);
        Array &operator[](unsigned int index);


        unsigned int getSize();
        void setSize(unsigned int);


        class InvalidRequest : public std::exception
        {
            public:
            virtual const char* what()const throw()
            {
                return("Invalid request detected!");
            }
        };
};





#endif