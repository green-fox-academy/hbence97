//
// Created by hegye on 2019. 02. 12..
//

#include "F16.h"

int F16::fight()
{
    int a = maxAmmo;
    maxAmmo = 0;
    return a * baseDamage;
}

int F16::refill(int a)
{
    if (a > maxAmmo) {
        return a - maxAmmo;
    } else {
        return a;
    }
}

std::string F16::getType()
{
    return ("The plane's type is F16");
}

std::string F16::getStatus()
{
    return (getType() + " Ammo: " + std::to_string(maxAmmo) + "Base damage: " + std::to_string(baseDamage) + " All damage: " + std::to_string(maxAmmo * baseDamage));
}

bool F16::isPriority()
{
    return false;
}
