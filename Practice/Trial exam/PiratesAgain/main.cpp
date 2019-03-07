#include <iostream>
#include "pirates.h"
#include "ship.h"

int main() {

    Pirates pirate("Jack", true, false);
    Pirates pirate1("Davie", false, true);
    Pirates pirate2("Will", false, false);
    Pirates pirate3("David", false, false);
    Pirates pirate4("Paul", false, false);
    Pirates pirate5("John", false, true);

    std::cout << pirate.toString() << std::endl;
    std::cout << pirate1.toString() << std::endl;
    std::cout << pirate2.toString() << std::endl;
    std::cout << pirate3.toString() << std::endl;
    std::cout << pirate4.toString() << std::endl;
    std::cout << pirate5.toString() << std::endl;

    Ship ship;
    ship.addPirates(pirate);
    ship.addPirates(pirate1);
    ship.addPirates(pirate2);
    ship.addPirates(pirate3);
    ship.addPirates(pirate4);
    ship.addPirates(pirate5);

    ship.prepareForBattle();
    ship.lastDayOnTheShip();

    std::cout << "The names of the poor pirates are " << std::endl;
    std::vector<std::string> poorPirateName = ship.getPoorPirate();
    for(int i = 0; i < poorPirateName.size(); i++) {
        std::cout << "\t" << poorPirateName[i] << std::endl;
    }
    std::cout << "The total amount of gold on the ship is " << ship.getGolds() << std::endl;


    return 0;
}