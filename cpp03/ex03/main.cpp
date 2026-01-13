#include "DiamondTrap.hpp"

int main()
{
    std::cout << std::endl;
    std::cout << BOLD << BLUE << "╔════════════════════════════════════╗" << RESET << std::endl;
    std::cout << BOLD << BLUE << "║      DiamondTrap Test Suite        ║" << RESET << std::endl;
    std::cout << BOLD << BLUE << "║  (FragTrap + ScavTrap Hybrid)      ║" << RESET << std::endl;
    std::cout << BOLD << BLUE << "╚════════════════════════════════════╝" << RESET << std::endl;
    std::cout << std::endl;

    // Test 1: Construction/Destruction Chaining with Multiple Inheritance
    std::cout << BOLD << YELLOW << "▶ Test 1: Construction & Destruction Chain (DiamondTrap)" << RESET << std::endl;
    std::cout << std::string(50, '-') << std::endl;
    {
        std::cout << "Creating DiamondTrap 'Diamond'..." << std::endl;
        DiamondTrap diamond("Diamond");
        std::cout << "\nDestroying DiamondTrap 'Diamond'..." << std::endl;
    }
    std::cout << std::endl;

    // Test 2: DiamondTrap Name Management
    std::cout << BOLD << YELLOW << "▶ Test 2: DiamondTrap Name Management" << RESET << std::endl;
    std::cout << std::string(50, '-') << std::endl;
    {
        DiamondTrap dt("Hybrid");
        dt.whoAmI();
    }
    std::cout << std::endl;

    // Test 3: DiamondTrap Inherited Stats
    std::cout << BOLD << YELLOW << "▶ Test 3: DiamondTrap Inherited Stats" << RESET << std::endl;
    std::cout << std::string(50, '-') << std::endl;
    {
        std::cout << "Creating DiamondTrap..." << std::endl;
        DiamondTrap hybrid("Hybrid");
        
        std::cout << "\nDiamondTrap inherited stats:" << std::endl;
        std::cout << "  HP: " << hybrid.getHitPoints() 
                  << " (from FragTrap)" << std::endl;
        std::cout << "  Energy: " << hybrid.getEnergyPoints() 
                  << " (from ScavTrap)" << std::endl;
        std::cout << "  Attack: " << hybrid.getAttackDamage() 
                  << " (from FragTrap)" << std::endl;
        
        std::cout << "\n  Name: Hybrid" << std::endl;
        std::cout << "  ClapTrap Name: Hybrid_clap_name" << std::endl;
    }
    std::cout << std::endl;

    // Test 4: DiamondTrap Basic Actions
    std::cout << BOLD << YELLOW << "▶ Test 4: DiamondTrap Basic Actions" << RESET << std::endl;
    std::cout << std::string(50, '-') << std::endl;
    {
        DiamondTrap warrior("Warrior");
        warrior.attack("Target");
        warrior.takeDamage(30);
        warrior.beRepaired(20);
        warrior.whoAmI();
    }
    std::cout << std::endl;

    // Test 5: DiamondTrap Attack Method (from ScavTrap)
    std::cout << BOLD << YELLOW << "▶ Test 5: DiamondTrap Uses ScavTrap's Attack" << RESET << std::endl;
    std::cout << std::string(50, '-') << std::endl;
    {
        std::cout << "Comparing attack methods:" << std::endl;
        
        ScavTrap scav("Scav");
        FragTrap frag("Frag");
        DiamondTrap diamond("Diamond");
        
        std::cout << "\nScavTrap attack:" << std::endl;
        scav.attack("Enemy");
        
        std::cout << "FragTrap attack:" << std::endl;
        frag.attack("Enemy");
        
        std::cout << "DiamondTrap attack (should match ScavTrap):" << std::endl;
        diamond.attack("Enemy");
    }
    std::cout << std::endl;

    // Test 6: DiamondTrap Intensive Combat
    std::cout << BOLD << YELLOW << "▶ Test 6: DiamondTrap Intensive Combat" << RESET << std::endl;
    std::cout << std::string(50, '-') << std::endl;
    {
        DiamondTrap warrior("Warrior");
        warrior.attack("Enemy1");
        warrior.takeDamage(40);
        warrior.beRepaired(30);
        warrior.attack("Enemy2");
        warrior.takeDamage(70);
        warrior.whoAmI();
    }
    std::cout << std::endl;

    // Test 7: Copy Constructor & Assignment
    std::cout << BOLD << YELLOW << "▶ Test 7: Copy & Assignment (DiamondTrap)" << RESET << std::endl;
    std::cout << std::string(50, '-') << std::endl;
    {
        DiamondTrap original("Original");
        original.takeDamage(20);
        
        std::cout << "\nCopying..." << std::endl;
        DiamondTrap copy(original);
        copy.whoAmI();
        
        std::cout << "\nAssigning..." << std::endl;
        DiamondTrap assigned("Assigned");
        assigned = original;
        assigned.whoAmI();
    }
    std::cout << std::endl;

    // Test 8: DiamondTrap Energy Depletion
    std::cout << BOLD << YELLOW << "▶ Test 8: DiamondTrap Energy Depletion" << RESET << std::endl;
    std::cout << std::string(50, '-') << std::endl;
    {
        DiamondTrap fighter("Fighter");
        std::cout << "Attacking and repairing until energy runs out..." << std::endl;
        for (int i = 0; i < 52; i++)
        {
            if (i % 2 == 0)
                fighter.attack("Enemy");
            else
                fighter.beRepaired(1);
        }
        std::cout << "\nAttempting actions with no energy..." << std::endl;
        fighter.attack("Ghost");
        fighter.beRepaired(5);
        fighter.whoAmI();
    }
    std::cout << std::endl;

    // Test 9: Multiple DiamondTraps
    std::cout << BOLD << YELLOW << "▶ Test 9: Multiple DiamondTraps Team" << RESET << std::endl;
    std::cout << std::string(50, '-') << std::endl;
    {
        std::cout << "Creating a team of DiamondTraps..." << std::endl;
        DiamondTrap alpha("Alpha");
        DiamondTrap beta("Beta");
        DiamondTrap gamma("Gamma");
        
        std::cout << "\nTeam identities:" << std::endl;
        alpha.whoAmI();
        std::cout << std::endl;
        beta.whoAmI();
        std::cout << std::endl;
        gamma.whoAmI();
        
        std::cout << "\nTeam attacking..." << std::endl;
        alpha.attack("Monster");
        beta.attack("Monster");
        gamma.attack("Monster");
    }
    std::cout << std::endl;

    // Test 10: Compare All Classes
    std::cout << BOLD << YELLOW << "▶ Test 10: Compare All Robot Types" << RESET << std::endl;
    std::cout << std::string(50, '-') << std::endl;
    {
        std::cout << "Creating all robot types..." << std::endl;
        ClapTrap clap("Clap");
        ScavTrap scav("Scav");
        FragTrap frag("Frag");
        DiamondTrap diamond("Diamond");
        
        std::cout << "\nStats Comparison:" << std::endl;
        std::cout << "ClapTrap  - HP: " << clap.getHitPoints() 
                  << " | Energy: " << clap.getEnergyPoints()
                  << " | Attack: " << clap.getAttackDamage() << std::endl;
        std::cout << "ScavTrap  - HP: " << scav.getHitPoints() 
                  << " | Energy: " << scav.getEnergyPoints()
                  << " | Attack: " << scav.getAttackDamage() << std::endl;
        std::cout << "FragTrap  - HP: " << frag.getHitPoints() 
                  << " | Energy: " << frag.getEnergyPoints()
                  << " | Attack: " << frag.getAttackDamage() << std::endl;
        std::cout << "DiamondTrap - HP: " << diamond.getHitPoints() 
                  << " | Energy: " << diamond.getEnergyPoints()
                  << " | Attack: " << diamond.getAttackDamage() << std::endl;
        
        std::cout << "\nAll attacking..." << std::endl;
        clap.attack("Target");
        scav.attack("Target");
        frag.attack("Target");
        diamond.attack("Target");
    }
    std::cout << std::endl;

    std::cout << BOLD << GREEN << "✓ All Tests Complete!" << RESET << std::endl;
    std::cout << std::endl;

    return 0;
}
