#ifndef INTERN_HPP
#define INTERN_HPP
#include "aform.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"



class Intern
{
    public:
        Intern();
        ~Intern();
        AForm* makeForm(std::string nameF, std::string target); 
        class erroreForm : public std::exception {};
    private:
        typedef struct s_forminebirichine
        {
            std::string formName;
            AForm* formType;
        }t_forminebirichine;
};

#endif