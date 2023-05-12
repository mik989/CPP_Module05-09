#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat Pippo("Pippo", 150);
        std::cout << Pippo << std::endl;
        Pippo.increment_grade();
        std::cout << Pippo << std::endl;
        Bureaucrat Luca("Luca", 49);
        Luca = Pippo;
        std::cout << Luca << std::endl;
        Pippo.decrement_grade();
        std::cout << Pippo << std::endl;
        Bureaucrat Giovanni("Giovanni", 10);
        std::cout << Giovanni << std::endl;
    }
    catch(Bureaucrat::GradeTooHighException& suca)
    {
        std::cout << "grado alto porcote!" << std::endl;
    }
    catch(Bureaucrat::GradeTooLowException& stocazzo)
    {
        std::cout << "grado basso porcote!" << std::endl;
    }
}