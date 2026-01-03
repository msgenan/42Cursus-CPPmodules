#include "ClapTrap.hpp"

static void printHeader(const std::string& title)
{
    std::cout << std::endl;
    std::cout << BOLD << BLUE << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << RESET << std::endl;
    std::cout << BOLD << "  " << title << RESET << std::endl;
    std::cout << BOLD << BLUE << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << RESET << std::endl;
    std::cout << std::endl;
}

static void printTest(const std::string& testName)
{
    std::cout << std::endl;
    std::cout << BOLD << YELLOW << ">>> " << testName << RESET << std::endl;
    std::cout << std::endl;
}

static void printStats(const ClapTrap& clap)
{
    std::cout << CYAN << "  [" << clap.getName() << "] "
              << "HP: " << clap.getHitPoints() 
              << " | Energy: " << clap.getEnergyPoints()
              << " | Damage: " << clap.getAttackDamage() << RESET << std::endl;
}

int main()
{
    printHeader("CLAPTRAP TEST SUITE");

    // Test 1: Constructor Tests
    printTest("Test 1: Constructor Tests");
    {
        ClapTrap defaultClap;
        ClapTrap namedClap("Robot");
        printStats(defaultClap);
        printStats(namedClap);
    }

    // Test 2: Copy Constructor Test
    printTest("Test 2: Copy Constructor Test");
    {
        ClapTrap original("Original");
        ClapTrap copy(original);
        printStats(original);
        printStats(copy);
    }

    // Test 3: Assignment Operator Test
    printTest("Test 3: Assignment Operator Test");
    {
        ClapTrap clap1("Alpha");
        ClapTrap clap2("Beta");
        
        std::cout << "Before assignment:" << std::endl;
        printStats(clap1);
        printStats(clap2);
        
        clap2 = clap1;
        
        std::cout << "After assignment:" << std::endl;
        printStats(clap1);
        printStats(clap2);
    }

    // Test 4: Basic Attack Test
    printTest("Test 4: Basic Attack Test");
    {
        ClapTrap warrior("Warrior");
        printStats(warrior);
        warrior.attack("Enemy");
        warrior.attack("Goblin");
        warrior.attack("Dragon");
        printStats(warrior);
    }

    // Test 5: Take Damage Test
    printTest("Test 5: Take Damage Test");
    {
        ClapTrap victim("Victim");
        printStats(victim);
        victim.takeDamage(3);
        printStats(victim);
        victim.takeDamage(5);
        printStats(victim);
        victim.takeDamage(10);  // Should die
        printStats(victim);
        victim.attack("Ghost");  // Cannot attack when dead
    }

    // Test 6: Repair Test
    printTest("Test 6: Repair Test");
    {
        ClapTrap healer("Healer");
        printStats(healer);
        healer.takeDamage(7);
        printStats(healer);
        healer.beRepaired(5);
        printStats(healer);
        healer.beRepaired(3);
        printStats(healer);
    }

    // Test 7: Energy Depletion Test
    printTest("Test 7: Energy Depletion Test");
    {
        ClapTrap tired("Tired");
        printStats(tired);
        
        // Use all 10 energy points
        for (int i = 1; i <= 10; i++)
        {
            tired.attack("Target");
        }
        
        printStats(tired);
        std::cout << std::endl << "Trying to attack with no energy:" << std::endl;
        tired.attack("Cannot");  // Should fail
        
        std::cout << "Trying to repair with no energy:" << std::endl;
        tired.beRepaired(5);  // Should fail
        printStats(tired);
    }

    // Test 8: Dead ClapTrap Test
    printTest("Test 8: Dead ClapTrap Test");
    {
        ClapTrap doomed("Doomed");
        printStats(doomed);
        doomed.takeDamage(10);  // Kill it
        printStats(doomed);
        
        std::cout << std::endl << "Trying actions when dead:" << std::endl;
        doomed.attack("Nobody");
        doomed.beRepaired(5);
        doomed.takeDamage(5);  // Already dead message
    }

    // Test 9: Combat Scenario
    printTest("Test 9: Combat Scenario");
    {
        ClapTrap fighter("Fighter");
        
        std::cout << "Round 1:" << std::endl;
        fighter.attack("Monster");
        fighter.takeDamage(4);
        printStats(fighter);
        
        std::cout << std::endl << "Round 2:" << std::endl;
        fighter.attack("Monster");
        fighter.beRepaired(2);
        printStats(fighter);
        
        std::cout << std::endl << "Round 3:" << std::endl;
        fighter.attack("Monster");
        fighter.takeDamage(6);
        printStats(fighter);
        
        std::cout << std::endl << "Round 4:" << std::endl;
        fighter.beRepaired(3);
        fighter.attack("Monster");
        printStats(fighter);
    }

    printHeader("ALL TESTS COMPLETED");
    
    return 0;
}
