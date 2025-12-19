#include "Zombie.hpp"
#include <iostream>

int main()
{
    std::cout << CYAN << "\n=== Creating Zombie Horde ===" << RESET << std::endl;
    
    int hordeSize = 5;
    Zombie* horde = zombieHorde(hordeSize, "Yoda");
    
    std::cout << YELLOW << "\nAll zombies announcing:" << RESET << std::endl;
    for (int i = 0; i < hordeSize; i++)
    {
        std::cout << "Zombie [" << i << "]: ";
        horde[i].announce();
    }
    
    std::cout << GREEN << "\nDeleting the horde..." << RESET << std::endl;
    delete[] horde;
    
    std::cout << CYAN << "\n=== Test Complete ===\n" << RESET << std::endl;
    
    return 0;
}