#include <iostream>

int main(int argc, char* args[]) {

    // Write a program that reads a number from the standard input,
    // Then prints "Odd" if the number is odd, or "Even" if it is even.

    int a;
    std::cout << "Tell me a number and I'll tell you if it's even or odd." << std::endl;
    std::cin >> a;

    if(a % 2 == 0) {
        std::cout << "Your number is even." << std::endl;
    } else {
        std::cout << "Your number is odd." << std::endl;
    }

    return 0;
}