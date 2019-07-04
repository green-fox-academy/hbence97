//
// Created by hegye on 2019. 07. 04..
//

#include "f16.h"

int F16::fight() {
    int allDamage = _baseDamage * _maxAmmo;
    return allDamage;
}

int F16::refill(int refillAmount) {
    int remainingAmmo;
    remainingAmmo = refillAmount - _maxAmmo;
    return remainingAmmo;
}

std::string F16::getType() {
    std::string type;
    type = "The aircraft's type is F16.\n";
    return type;
}

std::string F16::getStatus(std::string type, int ammo, int baseDamage, int allDamage) {
    _type = type;
    _maxAmmo = ammo;
    _baseDamage = baseDamage;
    allDamage = baseDamage + ammo;
    std::string status = "Type " + type + ", Ammo: " + std::to_string(ammo) + ", Base Damage: " + std::to_string(baseDamage) + ", All damage: " +
    std::to_string(allDamage) + "\n";
}

bool F16::isPriority() {
    return false;
}
