//
// Created by hegye on 2019. 02. 08..
//

#include "F35.h"

int F35::fight()
{
    int a = ammoStore;
    ammoStore = 0;

    return a * baseDamage;
}

int F35::refill(int b)
{
    if(b < maxAmmo - ammoStore)
        return b - (maxAmmo - ammoStore);
    else
        ammoStore += b;
    return 0;
}

std::string F35::getType()
{
    std::cout << " F35" << std::endl;
}

std::string F35::getStatus()
{
    std::cout << "Type F35, Ammo: " << ammoStore << "Base Damage: " << baseDamage << " All damage: " << baseDamage * ammoStore << std::endl;
}

bool F35::isPriority()
{
    return true;
}