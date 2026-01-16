#include "ClapTrap.hpp"

int main()
{
    std::cout << std::endl;
    std::cout << BOLD << BLUE << "╔════════════════════════════════════╗" << RESET << std::endl;
    std::cout << BOLD << BLUE << "║            ClapTrap Test           ║" << RESET << std::endl;
    std::cout << BOLD << BLUE << "╚════════════════════════════════════╝" << RESET << std::endl;
    std::cout << std::endl;

    // Test 1: Basic functionality
    std::cout << BOLD << YELLOW << "▶ Test 1: Basic Actions" << RESET << std::endl;
    std::cout << std::string(40, '-') << std::endl;
    {
        ClapTrap robot("Robot");
        robot.attack("Enemy");
        robot.takeDamage(3);
        robot.beRepaired(2);
    }
    std::cout << std::endl;

    // Test 2: Energy depletion
    std::cout << BOLD << YELLOW << "▶ Test 2: Energy Depletion" << RESET << std::endl;
    std::cout << std::string(40, '-') << std::endl;
    {
        ClapTrap fighter("Fighter");
        std::cout << "Attacking 11 times..." << std::endl;
        for (int i = 0; i < 11; i++)
            fighter.attack("Target");
    }
    std::cout << std::endl;

    // Test 3: Death scenario
    std::cout << BOLD << YELLOW << "▶ Test 3: Death Scenario" << RESET << std::endl;
    std::cout << std::string(40, '-') << std::endl;
    {
        ClapTrap victim("Victim");
        victim.takeDamage(10);
        std::cout << "Attempting actions while dead..." << std::endl;
        victim.attack("Ghost");
        victim.beRepaired(5);
    }
    std::cout << std::endl;

    std::cout << BOLD << GREEN << "✓ All Tests Complete!" << RESET << std::endl;
    std::cout << std::endl;

    return 0;
}
