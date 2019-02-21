#include <iostream>

int main(int argc, char* args[]) {

    // Write a program that asks for a number.
    // It would ask this many times to enter an integer,
    // if all the integers are entered, it should print the sum and average of these
    // integers like:
    //
    // Sum: 22, Average: 4.4
    int counter;
    double sum = 0;
    double average = 0;
    std::cout << "Tell me a number please! " << std::endl;
    std::cin >> counter;
    for (int i = 0; i < counter; ++i) {
        std::cout << "Tell me a number please! " << std::endl;
        int num;
        std::cin >> num;
        sum += num;
    }
    std::cout << sum << std::endl;
    average = sum / counter;
    std::cout << average;
    return 0;
}
