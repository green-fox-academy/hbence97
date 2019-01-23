#include <iostream>
#include <fstream>
#include <string>

int linecounter (std::string file) {
    std::ifstream myFile (file);
    std::string line;

    if (myFile.is_open()) {
        int numberoflines =0;
        while (getline(myFile, line)) {
            numberoflines +=1;
        } return numberoflines;
    } else {
        return 0;
    }
}


int main () {
    // Write a function that takes a filename as string,
    // then returns the number of lines the file contains.
    // It should return zero if it can't open the file


    std::cout << linecounter("myFile.txt");

    return 0;
}