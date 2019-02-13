//
// Created by hegye on 2019. 02. 12..
//

#include "F35.h"

int F35::fight()
{
    int b = maxAmmo;
    maxAmmo = 0;
    return b * baseDamage;
}

int F35::refill(int a)
{
    if (a > maxAmmo) {
        return a - maxAmmo;
    } else {
        return a;
    }
}

std::string F35::getType()
{
    return ("The plane's type is F35.");
}

std::string F35::getStatus()
{
    return (getType() + " Ammo: " + std::to_string(maxAmmo) + "Base damage: " + std::to_string(baseDamage) + " All damage: " + std::to_string(maxAmmo * baseDamage));
}

bool F35::isPriority()
{
    return true;
}