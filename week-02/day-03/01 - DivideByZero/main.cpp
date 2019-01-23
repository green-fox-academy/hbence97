#include <iostream>
#include <fstream>
// Create a function that takes a number
// divides ten with it,
// and prints the result.
// It should print "fail" if the parameter is 0

int main() {
    int a = 10;
    float b;
    std::cout << "Give me a number!" << std::endl;
    std::cin >> b;

    try {



        if (b == 0) {
            throw std::string("fail");
        }
        //std::cout << b / 10 << std::endl;
    } catch (std::string x) {
        std::cout <<  x << std::endl;
    }
return 0;
}