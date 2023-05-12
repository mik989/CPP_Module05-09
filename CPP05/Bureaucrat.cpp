#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name), _grade(grade)
{
    if (grade < 1)
        throw(GradeTooHighException{});
    else if (grade > 150)
        throw(GradeTooLowException{});
    else
        std::cout << this->getName() << " costruito" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& ref) :_name(ref._name)
{
    *this = ref;
    return;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& ref)
{
    if(this != &ref)
        this->_grade = ref._grade;
    return *this;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "smash" << std::endl;
}

std::string Bureaucrat::getName() const
{
    return(this->_name);
}

int Bureaucrat::getGrade() const
{
    return(this->_grade);
}

void    Bureaucrat::increment_grade()
{
    if (_grade >= 2)
    {
        this->_grade -= 1;
        std::cout << "Grado di " << this->getName() << " aumentato!" << std::endl;
    }
    else
        throw(GradeTooHighException{});
}

void    Bureaucrat::decrement_grade()
{
    if (_grade < 150)
    {
        this->_grade += 1;
        std::cout << "Grado di " << this->getName() << " diminuito!" << std::endl;
    }
    else
        throw(GradeTooLowException{});
}

std::ostream& operator<<(std::ostream& o, const Bureaucrat& ref)
{
    o << ref.getName() << ", bureaucrat grade " << ref.getGrade() << std::endl;
    return (o);
}