#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    std::cout << std::endl;
    std::cout << BOLD << BLUE << "╔════════════════════════════════════╗" << RESET << std::endl;
    std::cout << BOLD << BLUE << "║            FragTrap Test           ║" << RESET << std::endl;
    std::cout << BOLD << BLUE << "╚════════════════════════════════════╝" << RESET << std::endl;
    std::cout << std::endl;

    // Test 1: FragTrap Basic Actions
    std::cout << BOLD << YELLOW << "▶ Test 1: FragTrap Actions" << RESET << std::endl;
    std::cout << std::string(40, '-') << std::endl;
    {
        FragTrap frag("Fraggy");
        frag.attack("Enemy");
        frag.takeDamage(40);
        frag.beRepaired(25);
        frag.highFivesGuys();
    }
    std::cout << std::endl;

    // Test 2: Compare All Three Classes
    std::cout << BOLD << YELLOW << "▶ Test 2: Compare Stats" << RESET << std::endl;
    std::cout << std::string(40, '-') << std::endl;
    {
        ClapTrap clap("Clappy");
        ScavTrap scav("Scavy");
        FragTrap frag("Fraggy");
        
        std::cout << "ClapTrap: HP=" << clap.getHitPoints() 
                  << " Energy=" << clap.getEnergyPoints() 
                  << " Attack=" << clap.getAttackDamage() << std::endl;
        std::cout << "ScavTrap: HP=" << scav.getHitPoints() 
                  << " Energy=" << scav.getEnergyPoints() 
                  << " Attack=" << scav.getAttackDamage() << std::endl;
        std::cout << "FragTrap: HP=" << frag.getHitPoints() 
                  << " Energy=" << frag.getEnergyPoints() 
                  << " Attack=" << frag.getAttackDamage() << std::endl;
    }
    std::cout << std::endl;

    std::cout << BOLD << GREEN << "✓ All Tests Complete!" << RESET << std::endl;
    std::cout << std::endl;

    return 0;
}
