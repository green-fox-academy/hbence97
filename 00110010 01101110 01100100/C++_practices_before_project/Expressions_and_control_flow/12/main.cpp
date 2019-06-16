#include <iostream>

int main(int argc, char* args[]) {

    // Write a program that stores 3 sides of a cuboid as variables (doubles)
    // The program should write the surface area and volume of the cuboid like:
    //
    // Surface Area: 600
    // Volume: 1000

    double length = 10;
    double width = 20;
    double height = 5;
    double volume = length * width * height;
    double surface_area = 2 * (length * width) + 2 * (length * height) + 2 * (width * height);

    std::cout << "Surface area: " << surface_area << std::endl;
    std::cout << "Volume: " << volume << std::endl;

    return 0;
}