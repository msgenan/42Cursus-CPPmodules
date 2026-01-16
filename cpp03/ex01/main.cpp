#include "ScavTrap.hpp"

int main()
{
    std::cout << std::endl;
    std::cout << BOLD << BLUE << "╔════════════════════════════════════╗" << RESET << std::endl;
    std::cout << BOLD << BLUE << "║            ScavTrap Test           ║" << RESET << std::endl;
    std::cout << BOLD << BLUE << "╚════════════════════════════════════╝" << RESET << std::endl;
    std::cout << std::endl;

    // Test 1: Construction/Destruction Chaining
    std::cout << BOLD << YELLOW << "▶ Test 1: Construction & Destruction Chain" << RESET << std::endl;
    std::cout << std::string(40, '-') << std::endl;
    {
        ScavTrap scav("scav");
        scav.attack("Enemy");
        scav.guardGate();
    }
    std::cout << std::endl;

    // Test 2: ScavTrap vs ClapTrap Stats
    std::cout << BOLD << YELLOW << "▶ Test 2: ScavTrap vs ClapTrap Stats" << RESET << std::endl;
    std::cout << std::string(40, '-') << std::endl;
    {
        ClapTrap clap("Clap");
        ScavTrap scav("Scav");
        
        std::cout << "ClapTrap Stats: HP = " << clap.getHitPoints() 
                  << " Energy = " << clap.getEnergyPoints() 
                  << " Attack = " << clap.getAttackDamage() << std::endl;
        std::cout << "ScavTrap Stats: HP = " << scav.getHitPoints() 
                  << " Energy=" << scav.getEnergyPoints() 
                  << " Attack=" << scav.getAttackDamage() << std::endl;
    }
    std::cout << std::endl;

    std::cout << BOLD << GREEN << "✓ All Tests Complete!" << RESET << std::endl;
    std::cout << std::endl;

    return 0;
}
