#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <string>

#define RESET  "\033[0m"
#define BOLD   "\033[1m"
#define RED    "\033[31m"
#define GREEN  "\033[32m"

class HumanA {
private:
    std::string name;
    Weapon& weapon;

public:
    HumanA(std::string name, Weapon& weapon);
    void attack() const;
};

#endif
