#include <iostream>
    // Create a program that asks for two numbers
    // If the second number is not bigger than the first one it should print:
    // "The second number should be bigger"
    //
    // If it is bigger it should count from the first number to the second by one
    //
    // example:
    //
    // first number: 3, second number: 6, should print:
    //
    // 3
    // 4
    // 5
    int main(int argc, char* args[]) {
    int num1;
    int num2;
    std::cout << "Give me a number" << std::endl;
    std::cin >> num1;
    std::cout << "And another one" << std::endl;
    std::cin >> num2;

    if (num1 > num2) {
        std::cout << "The second number should be bigger" << std::endl;
    }
    while (num1 < num2) {
        std::cout << num1 << std::endl;
        num1 += 1;
    }
    for (int i = num1 ;i < num2; i++) {
    std::cout << i << std::endl;

    }

    return 0;
}