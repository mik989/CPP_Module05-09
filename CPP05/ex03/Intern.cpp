#include "Intern.hpp"

Intern::Intern()
{

}

Intern::~Intern()
{
    
}

AForm* Intern::makeForm(std::string nameF, std::string target)
{
    AForm* ret = NULL;
    t_forminebirichine Forms[3] =
    {
        {"robotomy request", new RobotomyRequestForm("robotomy request", target)},
        {"presidential pardon", new PresidentialPardonForm("presidential pardon", target)},
        {"shrubbery creation", new ShrubberyCreationForm("shrubbery creation", target)}
    };
    for(int i = 0; i < 3; i++)
    {
        if (nameF == Forms[i].formName)
        {
            ret = Forms[i].formType;
            std::cout << "Intern creates " <<  Forms[i].formName << std::endl;
        }  
        else
        {
            delete Forms[i].formType;
        }
    }
    if (ret == NULL)
        std::cout << "Intern could not create form." << std::endl;
    return(ret);
}
       // throw(erroreForm{});