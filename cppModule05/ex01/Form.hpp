#ifndef FORM_H
#define FORM_H

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat; 

class Form
{
    private:
        const std::string name;
        bool _signed;
        const int gradeToSign;
        const int gradeToExecute;

    public:
        //static int lowGradeFlag;

        Form();
        Form(std::string name);
        Form(std::string name, int gradeToSign, int gradeToExecute);
        Form(const Form &copy);
        ~Form();

        Form &operator=(const Form &copy);

        std::string getName() const;
        bool getSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;

        void beSigned(Bureaucrat &);

        void isBetween();

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char *what() const throw()
                {
                    return ("Form:Grade is too high");
                } 
        };

        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char *what() const throw()
                {
                    //if(!lowGradeFlag)
                        return ("Form:Grade is too low");
                    //return "";
                }
        };
        /*
        class FormAlreadySigned : public std::exception
        {
            public:
            virtual const char *what() const throw()
            {
                return ("Form:Form already signed");
            }
        };
        */
        
        
};

std::ostream& operator<<(std::ostream &o, const Form &a);

#endif