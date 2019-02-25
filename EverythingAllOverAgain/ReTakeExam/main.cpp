#include <iostream>
#include <vector>
std::vector <std::string> newArray(std::string inputString, std::vector<std::string> myVector);

int main() {
    std::string inputString1 = "apple";
    std::vector<std::string> firstVector = {"apple", "apply", "tuple", "alter"};
    std::vector<std::string> result = newArray(inputString1, firstVector);
    std::vector<std::string> expectedResult = {"apple", "apply", "tuple"};
    if(newArray(inputString1,firstVector) == expectedResult){
        std::cout << "First test passed" << std::endl;
    } else {
        std::cout << "First test failed" << std::endl;
    }

    return 0;
}

std::vector <std::string> newArray(std::string inputString, std::vector<std::string> myVector) {
    //Resizes, and copies from myVector into firstResult!
    std::vector<std::string> firstResult;
    for (int i = 0; i < myVector.size(); ++i) {
        std::string word = myVector[i];
        int hammingDistance = 0;
        for (int j = 0; j < inputString.size(); ++j) {
            if (inputString[j] != word[j]) {
                hammingDistance++;
            }
        }
        if (hammingDistance <= 3) {
            firstResult.push_back(word);
        }
    }
    return firstResult;
}