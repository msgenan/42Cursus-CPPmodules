#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    std::cout << std::endl;
    std::cout << BOLD << BLUE << "╔════════════════════════════════════╗" << RESET << std::endl;
    std::cout << BOLD << BLUE << "║  FragTrap, ScavTrap & ClapTrap     ║" << RESET << std::endl;
    std::cout << BOLD << BLUE << "║         Test Suite                 ║" << RESET << std::endl;
    std::cout << BOLD << BLUE << "╚════════════════════════════════════╝" << RESET << std::endl;
    std::cout << std::endl;

    // Test 1: Construction/Destruction Chaining
    std::cout << BOLD << YELLOW << "▶ Test 1: Construction & Destruction Chain (FragTrap)" << RESET << std::endl;
    std::cout << std::string(50, '-') << std::endl;
    {
        std::cout << "Creating FragTrap 'Frag'..." << std::endl;
        FragTrap frag("Frag");
        std::cout << "\nDestroying FragTrap 'Frag'..." << std::endl;
    }
    std::cout << std::endl;

    // Test 2: FragTrap Basic Actions
    std::cout << BOLD << YELLOW << "▶ Test 2: FragTrap Basic Actions" << RESET << std::endl;
    std::cout << std::string(50, '-') << std::endl;
    {
        FragTrap destroyer("Destroyer");
        destroyer.attack("Target");
        destroyer.takeDamage(40);
        destroyer.beRepaired(25);
        destroyer.highFivesGuys();
    }
    std::cout << std::endl;

    // Test 3: Compare All Three Classes
    std::cout << BOLD << YELLOW << "▶ Test 3: Compare ClapTrap, ScavTrap & FragTrap Stats" << RESET << std::endl;
    std::cout << std::string(50, '-') << std::endl;
    {
        std::cout << "Creating all three types of robots..." << std::endl;
        ClapTrap clap("Clappy");
        ScavTrap scav("Scavy");
        FragTrap frag("Fraggy");
        
        std::cout << "\nClapTrap Stats:" << std::endl;
        std::cout << "  HP: " << clap.getHitPoints() 
                  << " | Energy: " << clap.getEnergyPoints() 
                  << " | Attack: " << clap.getAttackDamage() << std::endl;
        
        std::cout << "ScavTrap Stats:" << std::endl;
        std::cout << "  HP: " << scav.getHitPoints() 
                  << " | Energy: " << scav.getEnergyPoints() 
                  << " | Attack: " << scav.getAttackDamage() << std::endl;
        
        std::cout << "FragTrap Stats:" << std::endl;
        std::cout << "  HP: " << frag.getHitPoints() 
                  << " | Energy: " << frag.getEnergyPoints() 
                  << " | Attack: " << frag.getAttackDamage() << std::endl;
        
        std::cout << "\nAll attacking..." << std::endl;
        clap.attack("Target");
        scav.attack("Target");
        frag.attack("Target");
    }
    std::cout << std::endl;

    // Test 4: FragTrap Intense Combat
    std::cout << BOLD << YELLOW << "▶ Test 4: FragTrap Intense Combat" << RESET << std::endl;
    std::cout << std::string(50, '-') << std::endl;
    {
        FragTrap warrior("Warrior");
        warrior.attack("Enemy1");
        warrior.takeDamage(50);
        warrior.beRepaired(40);
        warrior.attack("Enemy2");
        warrior.takeDamage(80);
        warrior.attack("Enemy3");
        warrior.highFivesGuys();
        std::cout << "Attempting actions while dead..." << std::endl;
        warrior.attack("Ghost");
        warrior.highFivesGuys();
    }
    std::cout << std::endl;

    // Test 5: FragTrap Special Ability
    std::cout << BOLD << YELLOW << "▶ Test 5: FragTrap High-Fives Party" << RESET << std::endl;
    std::cout << std::string(50, '-') << std::endl;
    {
        FragTrap frag1("Frag1");
        FragTrap frag2("Frag2");
        FragTrap frag3("Frag3");
        
        frag1.highFivesGuys();
        frag2.highFivesGuys();
        frag3.highFivesGuys();
    }
    std::cout << std::endl;

    // Test 6: Copy Constructor & Assignment
    std::cout << BOLD << YELLOW << "▶ Test 6: Copy & Assignment (FragTrap)" << RESET << std::endl;
    std::cout << std::string(50, '-') << std::endl;
    {
        FragTrap original("Original");
        original.takeDamage(30);
        
        std::cout << "\nCopying..." << std::endl;
        FragTrap copy(original);
        
        std::cout << "\nAssigning..." << std::endl;
        FragTrap assigned("Assigned");
        assigned = original;
    }
    std::cout << std::endl;

    // Test 7: FragTrap Energy Depletion
    std::cout << BOLD << YELLOW << "▶ Test 7: FragTrap Energy Depletion" << RESET << std::endl;
    std::cout << std::string(50, '-') << std::endl;
    {
        FragTrap fighter("Fighter");
        std::cout << "Attacking and repairing until energy runs out..." << std::endl;
        for (int i = 0; i < 102; i++)
        {
            if (i % 2 == 0)
                fighter.attack("Enemy");
            else
                fighter.beRepaired(1);
        }
        std::cout << "\nAttempting high-fives with no energy..." << std::endl;
        fighter.highFivesGuys();
    }
    std::cout << std::endl;

    // Test 8: Mixed Trio Actions
    std::cout << BOLD << YELLOW << "▶ Test 8: Mixed Trio in Action" << RESET << std::endl;
    std::cout << std::string(50, '-') << std::endl;
    {
        std::cout << "Creating a team..." << std::endl;
        ClapTrap scout("Scout");
        ScavTrap guardian("Guardian");
        FragTrap berserker("Berserker");
        
        std::cout << "\nTeam attacking the same enemy..." << std::endl;
        scout.attack("Monster");
        guardian.attack("Monster");
        berserker.attack("Monster");
        
        std::cout << "\nTeam taking damage..." << std::endl;
        scout.takeDamage(15);
        guardian.takeDamage(45);
        berserker.takeDamage(60);
        
        std::cout << "\nTeam repairs..." << std::endl;
        scout.beRepaired(5);
        guardian.beRepaired(20);
        berserker.beRepaired(30);
        
        std::cout << "\nSpecial abilities..." << std::endl;
        guardian.guardGate();
        berserker.highFivesGuys();
    }
    std::cout << std::endl;

    std::cout << BOLD << GREEN << "✓ All Tests Complete!" << RESET << std::endl;
    std::cout << std::endl;

    return 0;
}
