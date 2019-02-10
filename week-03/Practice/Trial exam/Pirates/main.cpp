#include <iostream>
#include "pirate.h"
#include "ship.h"

int main() {

    Pirate pirate("Jack", true, false);
    Pirate pirate1("David", false, true);
    Pirate pirate2("Will", false, false);

    std::cout << pirate.toString() << std::endl;
    std::cout << pirate1.toString() << std::endl;
    std::cout << pirate2.toString() << std::endl;

    Ship ship;
    ship.addPirate(pirate);
    ship.addPirate(pirate1);
    ship.addPirate(pirate2);

    ship.prepareForBattle();
    ship.lastDayOnTheShip();

    std::cout << "The names of the poor pirates are " << std::endl;
    std::vector<std::string> poorPiratesName = ship.getPoorPirates();
        for(int i = 0; i < poorPiratesName.size(); i++) {
            std::cout << "\t" << poorPiratesName[i] << std::endl;
        }
    std::cout << "The total amount of gold on the ship is " << ship.getGolds() << std::endl;


    return 0;
}