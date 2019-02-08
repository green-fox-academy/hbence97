//
// Created by hegye on 2019. 02. 08..
//

#include "F16.h"
#include "aircrafts.h"

int F16::fight()
{
    int a = ammoStore;
    ammoStore = 0;

    return a * baseDamage;
}

int F16::refill(int a) {

    int b = a - maxAmmo;
    if (a < maxAmmo - ammoStore)
        return a - (maxAmmo - ammoStore);
    else
    {
        ammoStore += a;
        return 0;
    }
}

std::string F16::getType()
{
    std::cout << "F16" << std::endl;
}

std::string F16::getStatus()
{
   std::cout << "Type F16, Ammo: " << ammoStore << "Base Damage: " << baseDamage << " All damage: " << baseDamage * ammoStore << std::endl;
}

bool F16::isPriority()
{
    return false;
}

F16::F16()
{
    maxAmmo = 8;
    baseDamage = 30;
    ammoStore = 0;
}