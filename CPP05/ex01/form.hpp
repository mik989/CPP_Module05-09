#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include <iomanip>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form 
{
    public:
        Form(const Form& ref);
        Form(std::string name, int signGrade, int execGrade);
        ~Form();
        Form& operator=(const Form& ref);
        void beSigned(const Bureaucrat& burocrate);
        const int            getSigned() const;
        const std::string    getName() const;
        const int            getGrade() const;
        class    GradeTooHighException : public std::exception {};
        class   GradeTooLowException: public std::exception {};

    private:
        const std::string	_FormName;
        bool               _isSigned;
        const int          _signGrade;
        const int          _execGrade;

};

std::ostream& operator<<(std::ostream& o, const Form& ref);

#endif