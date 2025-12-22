#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
    {
        Weapon club = Weapon("Green-bladed lightsaber ");
        HumanA ObiWan("ObiWan", club);
        ObiWan.attack();
        club.setType("Blue-bladed lightsaber ");
        ObiWan.attack();
    }

    {
        Weapon club = Weapon("Red-bladed Sith lightsaber");
        HumanB DartVader("DartVader");
        DartVader.attack();
        DartVader.setWeapon(club);
        DartVader.attack();
        club.setType("Dual-phase Sith lightsaber");
        DartVader.attack();
    }
    return 0;
}
