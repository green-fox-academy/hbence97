#include <iostream>

int main(int argc, char* args[]) {

    // Write a program that prints the numbers from 1 to 100.
    // But for multiples of three print “Fizz” instead of the number
    // and for the multiples of five print “Buzz”.
    // For numbers which are multiples of both three and five print “FizzBuzz”.
    int num = 0;
    while(num < 101) {
        if ((num % 3 == 0) && (num % 5 != 0)){
            std::cout << "Fizz" << std::endl;
            }
        if ((num % 5 == 0) && (num % 3 != 0)) {
            std::cout << "Buzz" << std::endl;
        }
        if ((num % 3 == 0) && (num % 5 == 0)) {
            std::cout << "FizzBuzz" << std::endl;
        }
        if ((num % 3 != 0) && (num % 5 != 0)) {
            std::cout << num << std::endl;
        }
    num++;
    }
    return 0;
}