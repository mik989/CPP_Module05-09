#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat Pippo("Pippo", 150);
        Form    formino("Formino", 15, 20);
        Pippo.signForm(formino);
        std::cout << formino.getSigned() << std::endl;

        std::cout << std::endl;

        Bureaucrat Ermy("Ermes_Conrad", 3);
        Ermy.signForm(formino);
        std::cout << formino.getSigned() << std::endl;

    }
    catch(Bureaucrat::GradeTooHighException& e)
    {
        std::cout << "grado alto porcote!" << std::endl;
    }
    catch(Bureaucrat::GradeTooLowException& e)
    {
        std::cout << "grado basso porcote!" << std::endl;
    }
}