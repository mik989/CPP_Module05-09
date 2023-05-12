#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string name, std::string target) : AForm(name, 25, 5), _target(target)
{

}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (this->getExecGrade() < executor.getGrade())
        throw(GradeTooLowException{});      
    else
    {
        std::cout << this->_target << " è stato graziato da Zaphod Beeblebrox" << std::endl;
    }
    
}