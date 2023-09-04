#ifndef ROBOTOMY_H
#define ROBOTOMY_H

#include "AForm.hpp"
#include <ctime>

class RobotomyRequestForm : public AForm
{
    private:
        std::string target;
    public:
        RobotomyRequestForm(void);
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(RobotomyRequestForm const &rhs);
        RobotomyRequestForm& operator=(RobotomyRequestForm const& scf);
        ~RobotomyRequestForm(void);

        bool execute(const Bureaucrat &executor)const;
};

#endif