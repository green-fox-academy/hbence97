#include <iostream>
    // Write a program that prints the numbers from 1 to 100.
    // But for multiples of three print “Fizz” instead of the number
    // and for the multiples of five print “Buzz”.
    // For numbers which are multiples of both three and five print “FizzBuzz”.
    int main(int argc, char* args[]) {
    int num = 0;
    while (num <=100) {
        std::cout << num << std::endl;
        num += 1;
    }
    if (num % 3) {
        std::cout <<"Fizz" << std::endl;
    }
    if (num % 5) {
        std::cout << "Buzz" << std::endl;
    }
    if (num % 3, 5) {
        std::cout << "FizzBuzz" << std::endl;
    }
    return 0;
}