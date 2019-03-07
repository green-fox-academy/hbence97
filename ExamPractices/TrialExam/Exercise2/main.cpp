#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

char counter(std::string fileName);

int main() {
    counter("log");
    return 0;
}

char counter(std::string fileName) {
    std::string result;
    int i, count[26];
    int max = 0, location;

    std::ifstream commonChar;
    commonChar.open(fileName);

    if (!commonChar.is_open())
        throw std::string("File cannot be opened");

    // std::string line;
    //while (getline(commonChar, line)) {
    //    std::stringstream lineStream(line);
    //}
    char frequency[26];
    for (int i = 0; i <= 26; ++i) {
        max = count[i];
        location = i;
    }
    return location + 'A';
}