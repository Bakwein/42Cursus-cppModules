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
        std::string refOutput;

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
                    return ("Grade is too high");
                } 
        };

        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char *what() const throw()
                {
                    return ("Grade is too low");
                }
        };
};

std::ostream& operator<<(std::ostream &o, const Form &a);

#endif