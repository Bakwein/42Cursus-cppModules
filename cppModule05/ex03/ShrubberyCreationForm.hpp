#ifndef SHRUBBERY_H
#define SHRUBBERY_H

#include "AForm.hpp"

#include <fstream>

class ShrubberyCreationForm : public AForm 
{
    private:
        std::string target;
    public:
        ShrubberyCreationForm(void);
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(ShrubberyCreationForm const &rhs);
        ShrubberyCreationForm& operator=(ShrubberyCreationForm const& scf);
        ~ShrubberyCreationForm(void);

        bool execute(const Bureaucrat &executor)const;
};

#endif