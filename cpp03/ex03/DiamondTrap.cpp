#include "DiamondTrap.hpp"

/* --- Orthodox Canonical Form --- */

DiamondTrap::DiamondTrap() : ClapTrap("default"), FragTrap(), ScavTrap(), _name("default")
{
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 30;
    ClapTrap::_name = _name + "_clap_name";
    std::cout << GREEN << "DiamondTrap default constructor called" << RESET << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name) 
    : ClapTrap(name), FragTrap(name), ScavTrap(name), _name(name)
{
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 30;
    ClapTrap::_name = name + "_clap_name";
    std::cout << GREEN << "DiamondTrap " << CYAN << _name << GREEN << " constructor called" << RESET << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) 
    : ClapTrap(other), FragTrap(other), ScavTrap(other), _name(other._name)
{
    std::cout << GREEN << "DiamondTrap copy constructor called" << RESET << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
    std::cout << YELLOW << "DiamondTrap assignment operator called" << RESET << std::endl;
    if (this != &other)
    {
        FragTrap::operator=(other);
        ScavTrap::operator=(other);
        _name = other._name;
    }
    return *this;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << RED << "DiamondTrap " << CYAN << _name << RED << " destructor called" << RESET << std::endl;
}

/* --- Member Functions --- */

void DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(void)
{
    std::cout << BOLD << CYAN << "DiamondTrap Name: " << _name << RESET << std::endl;
    std::cout << BOLD << CYAN << "ClapTrap Name: " << ClapTrap::_name << RESET << std::endl;
}
