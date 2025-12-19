#include "Zombie.hpp"

int main()
{
    std::cout << CYAN << "\n=== HEAP Zombie Test ===" << RESET << std::endl;
    Zombie *heapZombie = newZombie("Luke Skywalker");
    heapZombie->announce();
    std::cout << YELLOW << "Luke is still alive, can use again:" << RESET << std::endl;
    heapZombie->announce();
    delete heapZombie;
    
    std::cout << CYAN << "\n=== STACK Zombie Test ===" << RESET << std::endl;
    randomChump("Darth Vader");
    std::cout << GREEN << "Yoda died automatically!\n" << RESET << std::endl;
    
    return 0;
}
