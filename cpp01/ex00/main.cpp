#include "Zombie.hpp"

int main()
{
    Zombie *zombie = newZombie("luke");
    zombie->announce();
    delete zombie;

    randomChump("skywalker");

}
