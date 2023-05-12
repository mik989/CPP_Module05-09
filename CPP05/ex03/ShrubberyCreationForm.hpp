#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP
#include "aform.hpp"

class   ShrubberyCreationForm: public AForm
{
    public:
        ShrubberyCreationForm(std::string name, std::string target);
        ~ShrubberyCreationForm();
        virtual void execute(Bureaucrat const & executor) const;
    private:
        const std::string	_FormName;
        bool               _isSigned;
        const std::string   _target;
};

#endif