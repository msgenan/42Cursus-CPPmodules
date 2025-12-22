#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon& weapon) : name(name), weapon(weapon) {}

void HumanA::attack() const
{
    std::cout << GREEN << name << RESET
              << " attacks with their " << BOLD 
              << weapon.getType() << RESET
              << std::endl;
}
