#ifndef INTERN_HPP
#define INTERN_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
    private: 
        //

    public: 
        //
        Intern(void);
        Intern(Intern const &src);
        Intern& operator=(Intern const &rhs);
        ~Intern(void);

        AForm *makePresidential(std::string target);
        AForm *makeRobotomy(std::string target);
        AForm *makeShrubbery(std::string target);

        AForm *makeForm(std::string formName, std::string targetForm);
};

#endif