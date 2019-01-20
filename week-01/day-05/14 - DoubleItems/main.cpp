#include <iostream>
#include <string>
    // - Create an array variable named `numList`
    //   with the following content: `[3, 4, 5, 6, 7]`
    // - Double all the values in the array
    int main(int argc, char* args[]) {
    int numList[] = {4, 5, 6, 7};
    for(int i = 0; i < 4; i++) {
        std::cout << numList[i] * 2 << std::endl;

    }


    return 0;
}