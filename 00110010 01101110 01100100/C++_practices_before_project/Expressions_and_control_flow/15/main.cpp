#include <iostream>

int main(int argc, char* args[]) {

    // Write a program that asks for a double that is a distance in miles,
    // then it converts that value to kilometers and prints it

    double mile;

    std::cout << "Tell me the distance in miles and I'll convert it to km." << std::endl;
    std::cin >> mile;

    double mile_to_km = mile * 1.609;

    std::cout << "That is " << mile_to_km << " kilometers." << std::endl;

    return 0;
}