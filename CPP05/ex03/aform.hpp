#ifndef AForm_HPP
#define AForm_HPP

#include <iostream>
#include <string>
#include <exception>
#include <iomanip>
#include <fstream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm 
{
    public:
        AForm(const AForm& ref);
        AForm(std::string name, int signGrade, int execGrade);
        ~AForm();
        AForm& operator=(const AForm& ref);
        void beSigned(const Bureaucrat& burocrate);
        const int            getSigned() const;
        const std::string    getName() const;
        const int            getGrade() const;
        const int            getExecGrade() const;
        virtual void execute(Bureaucrat const & executor) const = 0;
        class    GradeTooHighException : public std::exception {};
        class   GradeTooLowException: public std::exception {};

    private:
        const std::string	_AFormName;
        bool               _isSigned;
        const int          _signGrade;
        const int          _execGrade;

};

std::ostream& operator<<(std::ostream& o, const AForm& ref);

#endif