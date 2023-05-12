#include "form.hpp"

Form::Form(std::string name, int signGrade, int execGrade) : _FormName(name), _signGrade(signGrade), _execGrade(execGrade)
{
    this->_isSigned = false;
    if (signGrade < 1 || execGrade < 1)
        throw(GradeTooHighException{});
    else if (signGrade > 150 || execGrade > 150)
        throw(GradeTooLowException{});
    else
        std::cout << this->getName() << " costruito" << std::endl;
}

Form::Form(const Form& ref) : _signGrade(ref._signGrade), _execGrade(ref._execGrade)
{
    *this = ref;
    return;
}

Form::~Form()
{
    std::cout << "Form mangiato dal gatto" << std::endl;
}

void Form::beSigned(const Bureaucrat& burocrate)
{
    if (this->_signGrade < burocrate.getGrade())
        throw(GradeTooLowException{});      
    else
    {
        this->_isSigned = true;
        std::cout << "il Form: " << this->getName() << " e' stato firmato da " << burocrate.getName() << std::endl;
    }
}

const std::string Form::getName() const
{
    return(this->_FormName);
}

const int Form::getGrade() const
{
    return(this->_signGrade);
}

const int Form::getSigned() const
{
    return(this->_isSigned);
}

Form& Form::operator=(const Form& ref)
{
    this->_isSigned = ref._isSigned;
    return *this;
}

std::ostream& operator<<(std::ostream& o, const Form& ref)
{
    o << ref.getName() << ", bureaucrat grade " << ref.getGrade() << std::endl;
    return (o);
}