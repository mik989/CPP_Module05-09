#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string name, std::string target) : AForm(name, 145, 137), _target(target)
{

}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    
    if (this->getExecGrade() < executor.getGrade())
        throw(GradeTooLowException{});      
    else
    {
        std::ofstream file(this->_target + "_shrubbery");
        file <<"                ,@@@@@@@,                   " << std::endl;
        file <<"        ,,,.   ,@@@@@@/@@,  .oo8888o.       " << std::endl;
        file <<"     ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o      " << std::endl;
        file <<"    ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'     " << std::endl;
        file <<"    %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'     " << std::endl;
        file <<"    %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'      " << std::endl;
        file <<"    `&%\\ ` /%&'    |.|        \\ '|8'        " << std::endl;
        file <<"        |o|        | |         | |          " << std::endl;
        file <<"        |.|        | |         | |          " << std::endl;
        file <<"     \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_  " << std::endl;
        file.close();
        std::cout << this->_target << " e' stato Shrubberyzzato con successo" << std::endl;
    }
    
}