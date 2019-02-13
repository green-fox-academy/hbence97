//
// Created by hegye on 2019. 02. 12..
//
#include "Aircraft.h"
#include "Carrier.h"

Carrier::Carrier(int ammo, int healthPoints)
{

}

int Carrier::fill()
{
    for (int i = 0; i <_aircrafts.size() ; ++i) {

    }

}

void Carrier::addAircraft(Aircraft aircrafts)
{
    _aircrafts.push_back(aircrafts);
}

std::string Carrier::getStatus()
{
    int totalDamage = 0;
    for (int i = 0; i < _aircrafts.size() ; ++i) {

        totalDamage = _aircrafts[i].getCurrentAmmo() * _aircrafts[i].getBaseDamage();

    }

}