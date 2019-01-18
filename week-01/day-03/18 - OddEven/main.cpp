#include <iostream>
    // Write a program that reads a number from the standard input,
    // Then prints "Odd" if the number is odd, or "Even" if it is even.
    int main(int argc, char* args[]) {

    int num;


    std::cout << "Give me a number" << std::endl;
    std::cin >> num;

    if (num  % 2 == 0) {
        std::cout << "Its an even number" << std::endl;
    } else {
        std::cout << "Its an odd number" << std::endl;
    }

    return 0;
}