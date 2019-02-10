#include <iostream>
#include <fstream>
#include <string>

int main () {
    // Write a program that opens a file called "my-file.txt", then prints
    // each line from the file.
    // You will have to create the file, you may use C-programming, although it is not mandatory

    /*std::ofstream myFile("my-file.txt");
    if (myFile.is_open());
    myFile << "valami szoveg \n";
    myFile << "masodik sor \n";

    myFile.close();
*/
    std::ifstream myFile ("my-file.txt");
    std::string text;
    while (std::getline (myFile,text)){

        std::cout << text << std::endl;
    }
return 0;
}