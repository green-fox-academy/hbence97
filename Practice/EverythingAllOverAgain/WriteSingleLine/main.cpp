#include <iostream>
#include <fstream>
#include <string>
// Open a file called "my-file.txt"
// Write your name in it as a single line
int main() {
//THIS IS HOW YOU WRITE IN A TEXT FILE!!
    std::ofstream file("my-file.txt");
    file << "Bence";
    file.close();

    return 0;
}