#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name)
{
    this->name = name;
    this->weapon = NULL;
}

void HumanB::setWeapon(Weapon& weapon)
{
    this->weapon = &weapon;
}

void HumanB::attack() const
{
    if (this->weapon)
    {
        std::cout << RED << name << RESET 
                  << " attacks with their " << BOLD 
                  << weapon->getType() << RESET 
                  << std::endl;
    }
    else
        std::cout << RED << name << RESET 
                  << BOLD << " has no weapon!" << RESET 
                  << std::endl;
}
