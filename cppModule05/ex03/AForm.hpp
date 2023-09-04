#ifndef AFORM_H
#define AFORM_H

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat; 

class AForm
{
    private:
        const std::string name;
        bool _signed;
        const int gradeToSign;
        const int gradeToExecute;

    public:
        static int lowGradeFlag;

        AForm();
        AForm(std::string name);
        AForm(std::string name, int gradeToSign, int gradeToExecute);
        AForm(const AForm &copy);
        ~AForm();

        AForm &operator=(const AForm &copy);

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
                    return ("AForm:Grade is too high");
                } 
        };

        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
        
        class AFormAlreadySigned : public std::exception
        {
            public:
                virtual const char *what() const throw()
                {
                    return ("AForm:AForm already signed");
                }
        };
        
        class AFormNotSigned : public std::exception
        {
            public:
                virtual const char *what() const throw()
                {
                    return ("AForm is not signed!");
                }

        };
        
        virtual bool execute(const Bureaucrat &executor)const = 0;
        
};

std::ostream& operator<<(std::ostream &o, const AForm &a);

#endif