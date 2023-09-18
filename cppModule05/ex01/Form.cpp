#include "Form.hpp"

//int Form::lowGradeFlag = 0;

Form::Form(): name("default"),_signed(false),gradeToSign(150),gradeToExecute(150)
{
    std::cout << "Default constructor called" << std::endl;

}

Form::Form(std::string name): name(name),_signed(false),gradeToSign(150),gradeToExecute(150)
{
    std::cout << "Name constructor called" << std::endl;
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute) : name(name),_signed(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    std::cout << "Constructor called" << std::endl;
    this->isBetween();
}

Form::~Form()
{
    std::cout << this->name <<"'s Form destructor called" << std::endl;
}

Form::Form(Form const& f) : name(f.name), _signed(f._signed), gradeToSign(f.gradeToSign), gradeToExecute(f.gradeToExecute)
{
    std::cout << "Copy const called" << std::endl;
    *this = f;
}

Form& Form::operator=(Form const &f)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if(this != &f)
    {
        this->_signed = f._signed;
    }
    return *this;
}

std::string Form::getName()const{return name;}
bool        Form::getSigned()const{return _signed;}
int         Form::getGradeToSign()const{return gradeToSign;}
int         Form::getGradeToExecute()const{return gradeToExecute;}


void    Form::beSigned(Bureaucrat &bur)
{
    if(bur.getGrade() > this->getGradeToSign())
    {
        std::cout << PURPLE << bur.getName() << " cannot sign " << this->getName() << " because grade problem" << RESET << std::endl;
        //lowGradeFlag = 1;
        throw Form::GradeTooLowException();
    }
    else if(_signed) //true
    {
        std::cout << PURPLE <<  bur.getName() << " cannot sign " << this->getName() << " because it's already signed" << RESET <<std::endl;
        //throw Form::FormAlreadySigned();
    }
    else if(!_signed) //false
    {
        _signed = true;
        bur.signCount++;
        std::cout << CYAN <<"Form " << this->getName() << " is signed by " << bur.getName() <<  RESET <<std::endl;
    }
}
/*
const char	*Form::GradeTooLowException::what() const throw()
{
    //if(!lowGradeFlag)
        return ("Form:Grade is too low");
    //return "";
}
*/

void    Form::isBetween()
{
    if(gradeToSign > 150 || gradeToExecute > 150)
        throw Form::GradeTooLowException();
    else if(gradeToSign < 1 || gradeToSign < 1)
        throw Form::GradeTooHighException();
}

std::ostream& operator<<(std::ostream& os, Form const& f)
{
    os << GREEN <<"name: "<< f.getName() << ", _signed: " << f.getSigned() << ", gradeToSign: "<< f.getGradeToSign() << ", gradeToExecute:"<< f.getGradeToExecute()<< std::endl << RESET;
    return os;
}