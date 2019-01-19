#include <iostream>
    // Write a program that asks for two numbers and prints the bigger one
    int main(int argc, char* args[]) {

    int num1;
    int num2;

    std::cout << "Tell me a number! " << std::endl;
    std::cin >> num1;
    std::cout << "and another one! " << std::endl;
    std::cin >> num2;

    if (num1 > num2) {
        std::cout << "The first number is the bigger one" << std::endl;
    }
    if (num1 < num2) {
        std::cout << "The second number is the bigger one" << std::endl;
    }
    return 0;
}