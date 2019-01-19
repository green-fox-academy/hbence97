#include <iostream>
    // Write a program that stores 3 sides of a cuboid as variables (doubles)
    // The program should write the surface area and volume of the cuboid like:
    //
    // Surface Area: 600
    // Volume: 1000
int main(int argc, char* args[]) {

    double a; //= 20
    double b; //= 30;
    double c; //= 40;

    int volume = a * b * c;
    int surface = 2 * ( a * b + a * c + b * c);

    std::cout << "what is the lenght of the cuboid? (in cm)" << std::endl;
    std::cin >> a;
    std::cout << "what is the width of the cuboid? (in cm)" << std::endl;
    std::cin >> b;
    std::cout << "what is the height of the cuboid? (in cm)" << std::endl;
    std::cin >> c;

    std::cout << "the volume is " << a * b * c << "cm^3" << std::endl;
    std::cout << "the surface area is " << 2 * ( a * b + a * c + b * c) << "cm^2" << std::endl;

    return 0;
}