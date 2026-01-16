#include "DiamondTrap.hpp"

int main()
{
    std::cout << std::endl;
    std::cout << BOLD << BLUE << "╔════════════════════════════════════╗" << RESET << std::endl;
    std::cout << BOLD << BLUE << "║          DiamondTrap Test          ║" << RESET << std::endl;
    std::cout << BOLD << BLUE << "╚════════════════════════════════════╝" << RESET << std::endl;
    std::cout << std::endl;

    // Test 1: Construction/Destruction & whoAmI
    std::cout << BOLD << YELLOW << "▶ Test 1: DiamondTrap Identity" << RESET << std::endl;
    std::cout << std::string(40, '-') << std::endl;
    {
        DiamondTrap diamond("Diamond");
        diamond.whoAmI();
        diamond.attack("Enemy");
    }
    std::cout << std::endl;

    // Test 2: DiamondTrap Inherited Stats
    std::cout << BOLD << YELLOW << "▶ Test 2: Inherited Stats" << RESET << std::endl;
    std::cout << std::string(40, '-') << std::endl;
    {
        DiamondTrap hybrid("Hybrid");
        
        std::cout << "DiamondTrap Stats:" << std::endl;
        std::cout << "  HP: " << hybrid.getHitPoints() << " (FragTrap)" << std::endl;
        std::cout << "  Energy: " << hybrid.getEnergyPoints() << " (ScavTrap)" << std::endl;
        std::cout << "  Attack: " << hybrid.getAttackDamage() << " (FragTrap)" << std::endl;
        hybrid.whoAmI();
    }
    std::cout << std::endl;

    std::cout << BOLD << GREEN << "✓ All Tests Complete!" << RESET << std::endl;
    std::cout << std::endl;

    return 0;
}
