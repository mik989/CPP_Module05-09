#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include "aform.hpp"
#include <cstdlib>

class   RobotomyRequestForm: public AForm
{
    public:
        RobotomyRequestForm(std::string name, std::string target);
        ~RobotomyRequestForm();
        virtual void execute(Bureaucrat const & executor) const;
    private:
        const std::string	_FormName;
        bool               _isSigned;
        const std::string   _target;
};

#endif