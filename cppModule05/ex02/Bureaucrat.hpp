#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"
//# include <cstdlib> 

//Virtual keyword indicates that the function can be overridden in derived classes.
//The const keyword indicates that the function cannot modify the object on which it is called. 
//The char* type indicates that the function returns a pointer to a null-terminated character string.
//The const char* return type is used because the what() function is used to return a message that describes the exception.
//what() function is a polymorphic function that is defined in the exception class.
//The virtual keyword allows the compiler to generate the correct code for calling the what() function, regardless of the type of the object that is thrown.
//2.const->The const keyword is used because the what() function is not supposed to modify the object on which it is called. The const keyword ensures that the compiler will not generate code that attempts to modify the object.

class AForm;

class Bureaucrat
{
    private:
        const std::string   name;
        int                 grade;
    public:
        //default
        Bureaucrat();
        
        //const.
        Bureaucrat(std::string name);
        Bureaucrat(int grade);
        Bureaucrat(std::string name, int grade);

       //copy const.
        Bureaucrat(Bureaucrat const& src);

        //copy assignment operator
        Bureaucrat& operator=(Bureaucrat const& br);

        //dest.
        ~Bureaucrat();

        int signCount;
        void isBetween();

        // increment and decrement

        void incrementGrade(int n);
        void decrementGrade(int n);

        //exceptions
        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return ("Grade is too high");
                }
        };

        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return ("Grade is too low");
                }
        };

        void signForm(AForm &f);

        std::string getName()const;
        int         getGrade()const;

        void        setGrade(int gr);

        void executeForm(AForm const & form);

};

std::ostream& operator<<(std::ostream &o, const Bureaucrat &a);

#endif