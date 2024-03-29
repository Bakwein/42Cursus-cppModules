#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include "Form.hpp"

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

class Form;

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

        void signForm(Form &f);

        std::string getName()const;
        int         getGrade()const;

        void        setGrade(int gr);

};

std::ostream& operator<<(std::ostream &o, const Bureaucrat &a);

#endif