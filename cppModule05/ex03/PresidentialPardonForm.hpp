#ifndef PRESIDENTIAL_H
#define PRESIDENTIAL_H

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private:
        std::string target;
    public:
        PresidentialPardonForm(void);
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(PresidentialPardonForm const &rhs);
        PresidentialPardonForm& operator=(PresidentialPardonForm const& scf);
        ~PresidentialPardonForm(void);

        bool execute(const Bureaucrat &executor)const;
};

#endif