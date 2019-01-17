#include <iostream>

    // Create a program that prints a few operations on two numbers: 22 and 13

    // Print the result of 13 added to 22

    // Print the result of 13 substracted from 22

    // Print the result of 22 multiplied by 13

    // Print the result of 22 divided by 13 (as a decimal fraction)

    // Print the integer part of 22 divided by 13

    // Print the reminder of 22 divided by 13

    int main(int argc, char* args[]) {

    int a = 13;
    int b = 22;

    std::cout << a + b << std::endl;

    std::cout << b - a << std::endl;

    std::cout << a * b << std::endl;

    std::cout << b / a << std::endl;

    std::cout << a % b << std::endl;

    return 0;
}