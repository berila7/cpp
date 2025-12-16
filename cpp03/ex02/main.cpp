#include "FragTrap.hpp"

int main()
{
    FragTrap frag("nmar");
    frag.attack("enemy");
    frag.takeDamage(30);
    frag.beRepaired(20);
    frag.highFivesGuys();
    return 0;
}