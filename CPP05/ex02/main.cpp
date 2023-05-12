#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try
    {
        Bureaucrat Pippo("Pippo", 160);
        AForm* formino = new ShrubberyCreationForm("Formino", "stronzo.txt");
        AForm* randomino = new RobotomyRequestForm("Formino", "random.txt");
        AForm* presidentino = new PresidentialPardonForm("Formino", "presidente.txt");

        Pippo.signForm(*formino);
        std::cout << (*formino).getSigned() << std::endl;

        Pippo.signForm(*randomino);
        std::cout << (*randomino).getSigned() << std::endl;

        Pippo.signForm(*presidentino);
        std::cout << (*presidentino).getSigned() << std::endl;

        std::cout << std::endl;

        Bureaucrat Ermy("Ermes_Conrad", 180);
        Ermy.signForm(*formino);
        std::cout << (*formino).getSigned() << std::endl;
        Ermy.executeForm(*formino);

        Ermy.signForm(*randomino);
        std::cout << (*randomino).getSigned() << std::endl;
        Ermy.executeForm(*randomino);

        Ermy.signForm(*presidentino);
        std::cout << (*presidentino).getSigned() << std::endl;
        Ermy.executeForm(*presidentino);

        delete formino;
        delete randomino;
        delete presidentino;
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