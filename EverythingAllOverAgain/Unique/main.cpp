#include <iostream>
#include <string>

int main(int argc, char* args[]) {

    //  Create a function that takes a list of numbers as a parameter
    //  Don't forget you have pass the size of the list as a parameter as well
    //  Returns a list of numbers where every number in the list occurs only once

    //  Example
    int numbers[8] = {1, 11, 34, 11, 52, 61, 1, 34};
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if(j != i) {
                if (numbers[i] == numbers[j]){}
            }

        }
    }
    std::cout << (unique(numbers)) << std::endl;
    //  should print: `[1, 11, 34, 52, 61]`  

    return 0;
}