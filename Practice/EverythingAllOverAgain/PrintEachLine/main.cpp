#include <iostream>
#include <fstream>
#include <string>
// Write a program that opens a file called "my-file.txt", then prints
// each line from the file.
// You will have to create the file, you may use C-programming, although it is not mandatory
int main () {
    //AND THIS IS HOW YOU PRINT OUT WHAT'S IN THE FILE!!
    std::ifstream testFile("my-file.txt");
    std::string theTextInTheFile;
    while (testFile >> theTextInTheFile) {
        std::cout << theTextInTheFile << std::endl;
    }

    return 0;
}