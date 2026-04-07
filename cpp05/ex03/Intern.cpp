#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern& other)
{
    (void)other;
}

Intern& Intern::operator=(const Intern& other)
{
    if (this != &other)
    {
        (void)other;
    }
    return *this;
}

Intern::~Intern()
{
}

AForm* Intern::_createShrubberyCreationForm(const std::string& target)
{
    return new ShrubberyCreationForm(target);
}

AForm* Intern::_createRobotomyRequestForm(const std::string& target)
{
    return new RobotomyRequestForm(target);
}

AForm* Intern::_createPresidentialPardonForm(const std::string& target)
{
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target)
{
    typedef AForm* (Intern::*FormCreator)(const std::string&);

    // Array of form names
    const std::string formNames[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    // Array of creator function pointers
    FormCreator creators[3] = {
        &Intern::_createShrubberyCreationForm,
        &Intern::_createRobotomyRequestForm,
        &Intern::_createPresidentialPardonForm
    };

    // Find and create the form
    for (int i = 0; i < 3; i++)
    {
        if (formName == formNames[i])
        {
            AForm* form = (this->*creators[i])(target);
            std::cout << "Intern creates " << form->getName() << std::endl;
            return form;
        }
    }

    // Form not found
    std::cerr << "Error: Form '" << formName << "' not found!" << std::endl;
    return NULL;
}
