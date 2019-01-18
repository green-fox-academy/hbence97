#include <iostream>

    // Write a program that asks for an integer that is a distance in kilometers,
    // then it converts that value to miles and prints it

    int main(int argc, char* args[]) {

        int distanceInKilometer;
        std::cout << "Please enter a distance in kilometer." << std::endl;
        std::cin >> distanceInKilometer;

        int distanceInMiles;

        distanceInMiles = distanceInKilometer * .62;
        std::cout << distanceInKilometer << " km is " << distanceInMiles << " miles." << std::endl;
        return 0;
    }