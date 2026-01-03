#include "ClapTrap.hpp"

/* --- Orthodox Canonical Form --- */

ClapTrap::ClapTrap()
    : _name("default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << GREEN << "ClapTrap default constructor called" << RESET << std::endl;
}

ClapTrap::ClapTrap(const std::string& name)
    : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << GREEN << "ClapTrap " << CYAN << _name << GREEN << " constructor called" << RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
    : _name(other._name), _hitPoints(other._hitPoints), 
      _energyPoints(other._energyPoints), _attackDamage(other._attackDamage)
{
    std::cout << GREEN << "ClapTrap copy constructor called" << RESET << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    std::cout << YELLOW << "ClapTrap assignment operator called" << RESET << std::endl;
    if (this != &other)
    {
        _name = other._name;
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
    }
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << RED << "ClapTrap " << CYAN << _name << RED << " destructor called" << RESET << std::endl;
}

/* --- Member Functions --- */

void ClapTrap::attack(const std::string& target)
{
    if (_hitPoints == 0)
    {
        std::cout << RED << "ClapTrap " << _name << " is dead and cannot attack!" << RESET << std::endl;
        return;
    }
    if (_energyPoints == 0)
    {
        std::cout << YELLOW << "ClapTrap " << _name << " has no energy to attack!" << RESET << std::endl;
        return;
    }
    
    _energyPoints--;
    std::cout << BOLD << "ClapTrap " << CYAN << _name << RESET << BOLD 
              << " attacks " << RED << target << RESET << BOLD
              << ", causing " << RED << _attackDamage << RESET << BOLD 
              << " points of damage!" << RESET << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (_hitPoints == 0)
    {
        std::cout << RED << "ClapTrap " << _name << " is already dead!" << RESET << std::endl;
        return;
    }
    
    if (_hitPoints <= amount)
    {
        _hitPoints = 0;
        std::cout << RED << "ClapTrap " << CYAN << _name << RED 
                  << " takes " << amount << " damage and is destroyed!" << RESET << std::endl;
    }
    else
    {
        _hitPoints -= amount;
        std::cout << RED << "ClapTrap " << CYAN << _name << RED 
                  << " takes " << amount << " damage! (" << _hitPoints << " HP left)" << RESET << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (_hitPoints == 0)
    {
        std::cout << RED << "ClapTrap " << _name << " is dead and cannot be repaired!" << RESET << std::endl;
        return;
    }
    if (_energyPoints == 0)
    {
        std::cout << YELLOW << "ClapTrap " << _name << " has no energy to repair!" << RESET << std::endl;
        return;
    }
    
    _energyPoints--;
    _hitPoints += amount;
    std::cout << GREEN << "ClapTrap " << CYAN << _name << GREEN 
              << " repairs itself for " << amount << " hit points! (" << _hitPoints << " HP)" << RESET << std::endl;
}

/* --- Accessors --- */

std::string ClapTrap::getName() const
{
    return _name;
}

unsigned int ClapTrap::getHitPoints() const
{
    return _hitPoints;
}

unsigned int ClapTrap::getEnergyPoints() const
{
    return _energyPoints;
}

unsigned int ClapTrap::getAttackDamage() const
{
    return _attackDamage;
}
