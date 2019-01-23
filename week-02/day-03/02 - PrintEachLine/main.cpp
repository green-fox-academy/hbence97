#include <iostream>
#include <fstream>
#include <string>
    // Write a program that opens a file called "my-file.txt", then prints
    // each line from the file.
    // You will have to create the file, you may use C-programming, although it is not mandatory
int main () {
    std::ifstream testFile("my-file.txt");

    std::string text;
    while (testFile >> text){
    std::cout << text << std::endl;

        }

return 0;
}