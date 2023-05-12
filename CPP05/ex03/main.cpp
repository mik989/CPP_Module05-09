#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{
    try
    {
        // Bureaucrat Pippo("Pippo", 150);
         //AForm* formino = new ShrubberyCreationForm("Formino", "stronzo.txt");
        // AForm* randomino = new RobotomyRequestForm("randomino", "random.txt");
        // AForm* presidentino = new PresidentialPardonForm("presidentino", "presidente.txt");

        // Pippo.signForm(*formino);
        // std::cout << (*formino).getSigned() << std::endl;

        // Pippo.signForm(*randomino);
        // std::cout << (*randomino).getSigned() << std::endl;

        // Pippo.signForm(*presidentino);
        // std::cout << (*presidentino).getSigned() << std::endl;

        // std::cout << std::endl;

        Bureaucrat Ermy("Ermes_Conrad", 3);
        // Ermy.signForm(*formino);
        // std::cout << (*formino).getSigned() << std::endl;
        // Ermy.executeForm(*formino);

        // Ermy.signForm(*randomino);
        // std::cout << (*randomino).getSigned() << std::endl;
        // Ermy.executeForm(*randomino);

        // Ermy.signForm(*presidentino);
        // std::cout << (*presidentino).getSigned() << std::endl;
        // Ermy.executeForm(*presidentino);

        Intern someRandomIntern;
        AForm* rr0;
        AForm* rr1;
        AForm* rr2;
        AForm* rr3;
        rr0 = someRandomIntern.makeForm("robotomy request", "Bender");
        rr1 = someRandomIntern.makeForm("presidential pardon", "Bender");
        rr2 = someRandomIntern.makeForm("shrubbery creation", "Bender");
        Ermy.executeForm(*rr2);
        rr3 = someRandomIntern.makeForm("dgh'ok", "Bender");
        delete rr0;
        delete rr1;
        delete rr2;
    }
    catch(Bureaucrat::GradeTooHighException& e)
    {
        std::cout << "grado alto porcote!" << std::endl;
    }
    catch(Bureaucrat::GradeTooLowException& e)
    {
        std::cout << "grado basso porcote!" << std::endl;
    } 
    /*catch(Intern::erroreForm& e)
    {
        std::cout << "Form Errato!" << std::endl;
    }*/
}