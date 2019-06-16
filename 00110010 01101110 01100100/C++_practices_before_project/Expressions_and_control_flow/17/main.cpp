#include <iostream>

int main(int argc, char* args[]) {

    // Write a program that asks for 5 integers in a row,
    // then it should print the sum and the average of these numbers like:
    //
    // Sum: 22, Average: 4.4
    double a, b, c, d, e;
    std::cout << "Tell me 5 numbers (Write the number first then press enter after each one)" << std::endl;

    std::cin >> a >> b >> c >> d >> e;

    double average = (a + b + c + d + e) / 5;
    double sum = a + b + c + d + e;

    std::cout <<  "The average of your numbers is: " << average << std::endl;
    std::cout << "The sum of your numbers is: " << sum << std::endl;

    return 0;
}