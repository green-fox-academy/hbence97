#include <iostream>

int main(int argc, char* args[]) {

    // Write a program that asks for two numbers and prints the bigger one
    int a, b;

    std::cout << "Tell me 2 numbers. (number then enter)" << std::endl;
    std::cin >> a >> b;

    if (a > b) {
        std::cout << a << std::endl;
    } else {
        std::cout << b << std::endl;
    }

    return 0;
}