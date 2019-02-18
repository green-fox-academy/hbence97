#include <iostream>
#include <vector>

std::vector<int> myArrayFunction(std::vector<int> inputArray, int n);

int main() {

    std::vector<int> firstArray = {0, 1, 5, 4};
    std::vector<int> firstResult = myArrayFunction(firstArray, 3);
    bool firstResultCorrect = (firstResult == std::vector<int>{0, 1, 25, 4});
    std::cout << "First test case result: " << firstResultCorrect << std::endl;

    std::vector<int> secondArray = {0, 3, 5, 4, 3, 6};
    std::vector<int> secondResult = myArrayFunction(secondArray, 2);
    bool secondResultCorrect = (secondResult == std::vector<int>{0, 18, 5, 24, 3, 36});
    std::cout << "Second test case result: " << secondResultCorrect << std::endl;

    return 0;
}

std::vector <int> myArrayFunction(std::vector<int> inputArray, int n)
{
    int max = 0;
    for (int i = 0; i < inputArray.size(); ++i) {
        if(inputArray[i] > max) {
            max = inputArray[i];
        }
    }
    for (int i = 0; i < inputArray.size(); ++i) {
        if ((i + 1) % n ==0 ){
            inputArray[i] *= max;
        }
    }
    return inputArray;
}