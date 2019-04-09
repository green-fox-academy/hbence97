#include <iostream>

int main(int argc, char* args[]) {

    // Write a program that reads a number from the standard input, then draws a
    // pyramid like this:
    //
    //
    //    *
    //   ***
    //  *****
    // *******
    //
    // The pyramid should have as many lines as the number was
    int rows;
    std::cout << "Give me how many rows you want" << std::endl;
    std::cin >> rows;

    for (int i = 0; i <= rows; ++i) {

        for (int j = i; j <= rows; ++j) {
            std::cout << " ";
        }

        for (int k = 0; k <= (i * 2) ; ++k) {
            std::cout << "*";
        }
        std::cout << "\n";
    }


    return 0;
}