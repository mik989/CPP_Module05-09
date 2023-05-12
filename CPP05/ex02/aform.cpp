#include "aform.hpp"

AForm::AForm(std::string name, int signGrade, int execGrade) : _AFormName(name), _signGrade(signGrade), _execGrade(execGrade)
{
    this->_isSigned = false;
    if (signGrade < 1 || execGrade < 1)
        throw(GradeTooHighException{});
    else if (signGrade > 150 || execGrade > 150)
        throw(GradeTooLowException{});
    else
        std::cout << this->getName() << " costruito" << std::endl;
}

AForm::AForm(const AForm& ref) : _signGrade(ref._signGrade), _execGrade(ref._execGrade)
{
    *this = ref;
    return;
}

AForm::~AForm()
{
    std::cout << "AForm mangiato dal gatto" << std::endl;
}

void AForm::beSigned(const Bureaucrat& burocrate)
{
    if (this->_signGrade < burocrate.getGrade())
        throw(GradeTooLowException{});      
    else
    {
        this->_isSigned = true;
        std::cout << "il AForm: " << this->getName() << " e' stato firmato da " << burocrate.getName() << std::endl;
    }
}

const std::string AForm::getName() const
{
    return(this->_AFormName);
}

const int AForm::getGrade() const
{
    return(this->_signGrade);
}

const int AForm::getExecGrade() const
{
    return(this->_execGrade);
}

const int AForm::getSigned() const
{
    return(this->_isSigned);
}

AForm& AForm::operator=(const AForm& ref)
{
    this->_isSigned = ref._isSigned;
    return *this;
}

std::ostream& operator<<(std::ostream& o, const AForm& ref)
{
    o << ref.getName() << ", bureaucrat grade " << ref.getGrade() << std::endl;
    return (o);
}