#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

#define RESET   "\033[0m"
#define CYAN    "\033[36m"
#define YELLOW  "\033[33m"
#define GREEN   "\033[32m"

class Zombie {
private:
    std::string name;

public:
    Zombie(std::string name);
    ~Zombie();
    void announce(void);
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif