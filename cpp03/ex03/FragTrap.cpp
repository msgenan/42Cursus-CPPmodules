#include "FragTrap.hpp"

/* --- Orthodox Canonical Form --- */

FragTrap::FragTrap() : ClapTrap()
{
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << GREEN << "FragTrap default constructor called" << RESET << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << GREEN << "FragTrap " << CYAN << _name << GREEN << " constructor called" << RESET << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
    std::cout << GREEN << "FragTrap copy constructor called" << RESET << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
    std::cout << YELLOW << "FragTrap assignment operator called" << RESET << std::endl;
    if (this != &other)
        ClapTrap::operator=(other);
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << RED << "FragTrap " << CYAN << _name << RED << " destructor called" << RESET << std::endl;
}

/* --- Member Functions --- */

void FragTrap::attack(const std::string& target)
{
    if (_hitPoints == 0)
    {
        std::cout << RED << "FragTrap " << _name << " is dead and cannot attack!" << RESET << std::endl;
        return;
    }
    if (_energyPoints == 0)
    {
        std::cout << YELLOW << "FragTrap " << _name << " has no energy to attack!" << RESET << std::endl;
        return;
    }
    
    _energyPoints--;
    std::cout << BOLD << "FragTrap " << CYAN << _name << RESET << BOLD 
              << " devastatingly attacks " << RED << target << RESET << BOLD
              << ", causing " << RED << _attackDamage << RESET << BOLD 
              << " points of damage!" << RESET << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << BOLD << YELLOW << "FragTrap " << CYAN << _name 
              << YELLOW << " is requesting high-fives! ✋" << RESET << std::endl;
}
