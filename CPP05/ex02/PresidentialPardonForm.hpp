#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP
#include "aform.hpp"
#include <cstdlib>

class   PresidentialPardonForm: public AForm
{
    public:
        PresidentialPardonForm(std::string name, std::string target);
        ~PresidentialPardonForm();
        virtual void execute(Bureaucrat const & executor) const;
    private:
        const std::string	_FormName;
        bool               _isSigned;
        const std::string   _target;
};

#endif