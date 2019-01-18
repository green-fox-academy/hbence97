#include <iostream>
    // Write a program that reads a number form the standard input,
    // If the number is zero or smaller it should print: Not enough
    // If the number is one it should print: One
    // If the number is two it should print: Two
    // If the number is more than two it should print: A lot
    int main(int argc, char* args[]) {

    int num;
    std::cout << "Give me a number" << std::endl;
    std::cin >> num;

    if (num <= 0 ) {
        std::cout << "Not enough" << std::endl;
    }
    if (num == 1) {
        std::cout << "One" << std::endl;
    }
    if (num == 2) {
        std::cout << "Two" << std::endl;
    }
    if (num >= 2 ) {
        std::cout << "A lot" << std::endl;
    }

    return 0;
}