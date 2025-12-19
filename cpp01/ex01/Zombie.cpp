#include "Zombie.hpp"

Zombie::Zombie()
{
    this->name = "";
}

Zombie::Zombie(std::string name)
{
    this->name = name;
}

void Zombie::setName(std::string name)
{
    this->name = name;
}

Zombie::~Zombie()
{
    std::cout << name << " is destroyed" << std::endl;
}

void Zombie::announce(void)
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
