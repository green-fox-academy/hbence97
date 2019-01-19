#include <iostream>
    // Write a program that asks for 5 integers in a row,
    // then it should print the sum and the average of these numbers like:
    //
    // Sum: 22, Average: 4.4
int main(int argc, char* args[]) {

    int a, b, c, d, e;
    double avg;
    std::cout << "Tell me 5 numbers" << std::endl;
    std::cin >> a,
    std::cin >> b;
    std::cin >> c;
    std::cin >> d;
    std::cin >> e;
    int f = a + b + c + d + e;
    avg = f / 5;

    std::cout << "Sum: " << f << ", Average: " << avg << std::endl;

    return 0;
}