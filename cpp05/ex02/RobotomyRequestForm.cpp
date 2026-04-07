#include "RobotomyRequestForm.hpp"
#include <ctime>

static bool seeded = false;

RobotomyRequestForm::RobotomyRequestForm() 
    : AForm("RobotomyRequestForm", 72, 45), _target("default_target") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) 
    : AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) 
    : AForm(other), _target(other._target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) 
{
    if (this != &other)
    {
        this->_target = other._target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}


void RobotomyRequestForm::executeAction() const 
{
    if (!seeded)
    {
        srand(static_cast<unsigned>(time(0)));
        seeded = true;
    }

    std::cout << "* Bzzzzzztt... Drrrrrrrrr... (Intense drilling noises) *" << std::endl;

    if (rand() % 2 == 0)
    {
        std::cout << this->_target << " has been robotomized successfully!" << std::endl;
    }
    else
    {
        std::cout << "The robotomy on " << this->_target << " failed." << std::endl;
    }
}
