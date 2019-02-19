#include <iostream>
#include <string>

int main(int argc, char* args[]) {

    // - Create an array variable named `aj`
    //   with the following content: `[3, 4, 5, 6, 7]`
    // - Reverse the order of the elements in `aj`
    // - Print the elements of the reversed `aj`
    int aj[5] = {3, 4, 5, 6, 7};
    int size = sizeof(aj)/sizeof(int);

    for (int i = size - 1; i >= 0; i--) {
        std::cout << aj[i] << " ";
    }
    std::cout << "\n";
    return 0;
}