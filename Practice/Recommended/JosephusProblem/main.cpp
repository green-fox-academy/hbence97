#include <iostream>

int whoWillSurvive(int players);
int main() {

    std::cout << "How many people do you want to be participated in your game? " << std::endl;
    int numberOfPeople;
    std::cin >> numberOfPeople;
    std::cout << "And the winner is " << whoWillSurvive(numberOfPeople);
    return 0;
}

int whoWillSurvive(int players){
    int theGroup[players];
    for (int i = 0; i < players; ++i) {
        theGroup[i] = i + 1;
    }
    bool killer = false;
    int alive = players;
    while (alive > 1) {
        for (int i = 0; i < players; ++i) {
            if (theGroup[i] != 0){
                if (killer){
                    theGroup[i] = 0;
                    alive -= 1;
                }
                killer = !killer;
            }
        }
    }
    for (int i = 0; i < players; ++i) {
        if (theGroup[i] != 0) return theGroup[i];
    }
}