#include "ScavTrap.hpp"

int main()
{
    std::cout << std::endl;
    std::cout << BOLD << BLUE << "╔════════════════════════════════════╗" << RESET << std::endl;
    std::cout << BOLD << BLUE << "║   ScavTrap & ClapTrap Test Suite   ║" << RESET << std::endl;
    std::cout << BOLD << BLUE << "╚════════════════════════════════════╝" << RESET << std::endl;
    std::cout << std::endl;

    // Test 1: Construction/Destruction Chaining
    std::cout << BOLD << YELLOW << "▶ Test 1: Construction & Destruction Chain" << RESET << std::endl;
    std::cout << std::string(50, '-') << std::endl;
    {
        std::cout << "Creating ScavTrap 'Serena'..." << std::endl;
        ScavTrap serena("Serena");
        std::cout << "\nDestroying ScavTrap 'Serena'..." << std::endl;
    }
    std::cout << std::endl;

    // Test 2: ScavTrap Basic Actions
    std::cout << BOLD << YELLOW << "▶ Test 2: ScavTrap Basic Actions" << RESET << std::endl;
    std::cout << std::string(50, '-') << std::endl;
    {
        ScavTrap guardian("Guardian");
        guardian.attack("Intruder");
        guardian.takeDamage(30);
        guardian.beRepaired(20);
        guardian.guardGate();
    }
    std::cout << std::endl;

    // Test 3: ScavTrap vs ClapTrap Stats
    std::cout << BOLD << YELLOW << "▶ Test 3: ScavTrap vs ClapTrap Stats" << RESET << std::endl;
    std::cout << std::string(50, '-') << std::endl;
    {
        std::cout << "Creating both robots..." << std::endl;
        ClapTrap clap("Clappy");
        ScavTrap scav("Scavy");
        
        std::cout << "\nClapTrap Stats:" << std::endl;
        std::cout << "  HP: " << clap.getHitPoints() 
                  << " | Energy: " << clap.getEnergyPoints() 
                  << " | Attack: " << clap.getAttackDamage() << std::endl;
        
        std::cout << "ScavTrap Stats:" << std::endl;
        std::cout << "  HP: " << scav.getHitPoints() 
                  << " | Energy: " << scav.getEnergyPoints() 
                  << " | Attack: " << scav.getAttackDamage() << std::endl;
        
        std::cout << "\nBoth attacking..." << std::endl;
        clap.attack("Target");
        scav.attack("Target");
    }
    std::cout << std::endl;

    // Test 4: ScavTrap Heavy Combat
    std::cout << BOLD << YELLOW << "▶ Test 4: ScavTrap Heavy Combat" << RESET << std::endl;
    std::cout << std::string(50, '-') << std::endl;
    {
        ScavTrap warrior("Warrior");
        warrior.attack("Enemy1");
        warrior.takeDamage(60);
        warrior.beRepaired(30);
        warrior.attack("Enemy2");
        warrior.takeDamage(70);
        std::cout << "Attempting actions while dead..." << std::endl;
        warrior.attack("Ghost");
        warrior.guardGate();
    }
    std::cout << std::endl;

    // Test 5: ScavTrap Energy Test
    std::cout << BOLD << YELLOW << "▶ Test 5: ScavTrap Energy Depletion" << RESET << std::endl;
    std::cout << std::string(50, '-') << std::endl;
    {
        ScavTrap fighter("Fighter");
        std::cout << "Attacking and repairing until energy runs out..." << std::endl;
        for (int i = 0; i < 52; i++)
        {
            if (i % 2 == 0)
                fighter.attack("Enemy");
            else
                fighter.beRepaired(1);
        }
        std::cout << "\nAttempting gate keeper mode with no energy..." << std::endl;
        fighter.guardGate();
    }
    std::cout << std::endl;

    // Test 6: Copy Constructor & Assignment
    std::cout << BOLD << YELLOW << "▶ Test 6: Copy & Assignment" << RESET << std::endl;
    std::cout << std::string(50, '-') << std::endl;
    {
        ScavTrap original("Original");
        original.takeDamage(20);
        
        std::cout << "\nCopying..." << std::endl;
        ScavTrap copy(original);
        
        std::cout << "\nAssigning..." << std::endl;
        ScavTrap assigned("Assigned");
        assigned = original;
    }
    std::cout << std::endl;

    // Test 7: Gate Keeper Special
    std::cout << BOLD << YELLOW << "▶ Test 7: Multiple Gate Keepers" << RESET << std::endl;
    std::cout << std::string(50, '-') << std::endl;
    {
        ScavTrap keeper1("Alpha");
        ScavTrap keeper2("Beta");
        ScavTrap keeper3("Gamma");
        
        keeper1.guardGate();
        keeper2.guardGate();
        keeper3.guardGate();
    }
    std::cout << std::endl;

    std::cout << BOLD << GREEN << "✓ All Tests Complete!" << RESET << std::endl;
    std::cout << std::endl;

    return 0;
}
