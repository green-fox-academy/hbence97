#include <iostream>
    // Write a program that asks for two integers
    // The first represents the number of chickens the farmer has
    // The second represents the number of pigs owned by the farmer
    // It should print how many legs all the animals have
    int main(int argc, char* args[]) {
    int num1;
    int num2;

    std::cout << "How many chickens does the farmer has? "<< std::endl;
    std::cin >> num1;
    std::cout << "How many pigs does the farmer has? " << std::endl;
    std::cin >> num2;

    std::cout << "All the animals have " << num1 * 2 + num2 * 4 << " legs" << std::endl;

    return 0;
}