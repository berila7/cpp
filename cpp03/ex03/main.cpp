#include "DiamondTrap.hpp"

int main()
{
    DiamondTrap diamond("moha");
    diamond.attack("enemy");
    diamond.takeDamage(30);
    diamond.beRepaired(20);
    diamond.highFivesGuys();
    diamond.attack("namr");
    diamond.whoAmI();
    return 0;
}