#include <iostream>

int main(int argc, char* args[]) {

    // Write a program that asks for two integers
    // The first represents the number of chickens the farmer has
    // The second represents the number of pigs owned by the farmer
    // It should print how many legs all the animals have
    int number_of_chickens;
    int number_of_pigs;

    std::cout << "Tell me how many chickens and pigs (in this order) the farmer has." << std::endl;
    std::cin >> number_of_chickens >> number_of_pigs;

    int chicken_legs = number_of_chickens * 2;
    int pig_legs = number_of_pigs * 4;

    std::cout << "All the animals have " << chicken_legs + pig_legs << " legs." << std::endl;

    return 0;
}