#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string name, std::string target) : AForm(name, 75, 45), _target(target)
{

}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if (this->getExecGrade() < executor.getGrade())
        throw(GradeTooLowException{});      
    else
    {
        bool randomBool;
        std::srand(std::time(nullptr));
        randomBool = (std::rand() % 2) == 0;
        if(randomBool == true)
        {
            std::cout << this->_target << " e' stato robotomizzato con successo il 50% delle volte" << std::endl;
            std::ofstream file(this->_target);
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
        }
        else
            std::cout << "La robotomizzazione è fallita " << std::endl;
    }
    
}