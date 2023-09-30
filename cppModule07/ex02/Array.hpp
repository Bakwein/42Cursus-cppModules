#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>


# define BLACK        "\033[0;30m"
# define RED        "\033[0;31m"
# define GREEN        "\033[0;32m"
# define YELLOW        "\033[0;33m"
# define BLUE        "\033[0;34m"
# define PURPLE        "\033[0;35m"
# define CYAN        "\033[0;36m"
# define WHITE        "\033[0;37m"
# define END        "\033[m"
# define RESET        "\033[0m"
# define B_CYAN         "\033[1;36m"
# define B_BLUE         "\033[1;34m"
# define B_YELLOW     "\033[1;33m"
# define B_GREEN         "\033[1;32m"
# define B_RED         "\033[1;31m"
# define B_RESET         "\033[1m"

template <typename T>
class Array
{
    private:
        T *ptr;
        unsigned int _size;


    public:
        //
        Array() : _size(0)
        {
            std::cout << "Default const." << std::endl;
            ptr = new T[_size];
        }

        Array(unsigned int n): _size(n)
        {
            std::cout << "unsig. int const." << std::endl;
            ptr = new T[_size];
        }
        
        Array(const Array &a) : _size(a.getSize())
        {
            std::cout << "Copy const." << std::endl;
            ptr = NULL;
            *this = a;
        }

        Array& operator=(const Array &a)
        {
            if(this->ptr == NULL)
                delete [] this->ptr;
            if(this != &a)
            {
                this->_size = a.getSize();
                ptr = new T[_size];
                for(unsigned int i = 0; i < _size ; i++)
                {
                    ptr[i] = a[i];
                }
            }
            return (*this);
        }

        /*
         cannot assign to return value because function 'operator[]' returns a const value
        numbers[i] = value;*/ 
        
        T &operator[](unsigned int index)
        {   
            
            if(index >= 0 && index < _size)
		   		return(ptr[index]);
		    else
		   		throw std::exception();
         
        }
        


        /*
        error: no viable overloaded operator[] for type 'const Array<int>'
                    ptr[i] = a[i];
        */
        const T& operator[](unsigned int index) const
        {
			if(index >= 0 && index < _size)
			   	return(ptr[index]);
			else
				throw std::exception();
        }
        
        

       ~Array(void)
       {
        delete[] ptr;
       } 


        unsigned int getSize()const{return _size;}
        void setSize(unsigned int size){this->_size = size;}




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