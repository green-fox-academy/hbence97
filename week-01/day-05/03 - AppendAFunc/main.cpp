#include <iostream>
#include <string>
    // - Create a string variable named `typo` and assign the value `Chinchill` to it
    // - Write a function called `appendAFunc` that gets a string as an input,
    //   appends an 'a' character to its end and returns with a string
    //
    // - Print the result of `appendAFunc(typo)`
    void AppendAFunc(std::string);

    int main(int argc, char* args[]) {
    std::string typo = "Chinchill";
    AppendAFunc(typo);
    return 0;
}

void AppendAFunc(std::string typo) {
    std::cout << typo << "a" << std::endl;

}