#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>
#include <iomanip>
#include "form.hpp"
class Form;

class Bureaucrat
{
    public:
        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat& ref);
        ~Bureaucrat();
        Bureaucrat& operator=(const Bureaucrat& ref);
        class    GradeTooHighException : public std::exception {};
        class   GradeTooLowException: public std::exception {};
        std::string getName() const;
        int            getGrade() const;
        void    increment_grade();
        void    decrement_grade();
        void    signForm(Form& form);
    private:
        const std::string	_name;
        int					_grade;

};

std::ostream& operator<<(std::ostream& o, const Bureaucrat& ref);

#endif