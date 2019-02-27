#include <stdio.h>
// Write a program that stores 3 sides of a cuboid as variables (doubles)
// You should get these variables via console input
// The program should write the surface area and volume of the cuboid like:
//
// Surface Area: 600
// Volume: 1000
int main() {
    double a = 200;
    double b = 300;
    double c = 500;
    double volume = a * b * c;
    double surfaceArea = 2 * (a * b) + 2 * (a * c) + 2 * (b * c);
    printf("The volume is: %.0f\n", volume);
    printf("The surface area is: %.0f\n", surfaceArea);
    return 0;
}