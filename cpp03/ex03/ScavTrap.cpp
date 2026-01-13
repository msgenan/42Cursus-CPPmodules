#include "ScavTrap.hpp"

/* --- Orthodox Canonical Form --- */

ScavTrap::ScavTrap() : ClapTrap()
{
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << GREEN << "ScavTrap default constructor called" << RESET << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << GREEN << "ScavTrap " << CYAN << _name << GREEN << " constructor called" << RESET << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
    std::cout << GREEN << "ScavTrap copy constructor called" << RESET << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    std::cout << YELLOW << "ScavTrap assignment operator called" << RESET << std::endl;
    if (this != &other)
        ClapTrap::operator=(other);
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << RED << "ScavTrap " << CYAN << _name << RED << " destructor called" << RESET << std::endl;
}

/* --- Member Functions --- */

void ScavTrap::attack(const std::string& target)
{
    if (_hitPoints == 0)
    {
        std::cout << RED << "ScavTrap " << _name << " is dead and cannot attack!" << RESET << std::endl;
        return;
    }
    if (_energyPoints == 0)
    {
        std::cout << YELLOW << "ScavTrap " << _name << " has no energy to attack!" << RESET << std::endl;
        return;
    }
    
    _energyPoints--;
    std::cout << BOLD << "ScavTrap " << CYAN << _name << RESET << BOLD 
              << " fiercely attacks " << RED << target << RESET << BOLD
              << ", causing " << RED << _attackDamage << RESET << BOLD 
              << " points of damage!" << RESET << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << BOLD << BLUE << "ScavTrap " << CYAN << _name 
              << BLUE << " is now in Gate keeper mode!" << RESET << std::endl;
}
