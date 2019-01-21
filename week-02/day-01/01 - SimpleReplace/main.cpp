#include <iostream>
#include <string>
// I would like to replace "dishwasher" with "galaxy" in this example, but it has a problem.
// Please fix it for me!
// Expected output: In a galaxy far far away
int main(int argc, char* args[])
{
    std::string sentence("In a dishwasher far far away");
    std::string from = "dishwasher";

    int start_pos = sentence.find(from);
    if (start_pos == std::string::npos)
        std::cout << "Cannot replace" << std::endl;
    else
        sentence.replace(start_pos, from.length(), "galaxy");

    std::cout << sentence << std::endl;
    return 0;
}