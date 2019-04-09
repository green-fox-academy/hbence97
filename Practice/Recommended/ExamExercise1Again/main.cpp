#include <iostream>
#include <vector>

std::vector <int>  newArray(std::vector<int> testVector, int testNumber);

int main() {

    std::vector<int> arr = {0, 1, 5, 4};
    int n = 3;
    newArray(arr, n);
    std::vector<int> arr2 = newArray(arr, n);
    for (int i = 0; i < arr2.size(); ++i) {
        std::cout << arr2[i] << " ";
    }

    return 0;
}

std::vector <int>  newArray(std::vector<int> testVector, int testNumber){

    std::vector <int> firstResult;
    firstResult.resize(testVector.size());
    for (int i = 0; i < testVector.size(); ++i) {
        firstResult[i] = testVector[i];
    }
    int maxValue = 0;
    for (int j = 0; j < firstResult.size(); ++j) {
        if (j > maxValue)
            maxValue = firstResult[j];
    }
    for (int k = 0; k < firstResult.size(); ++k) {
        if ((k + 1) % testNumber == 0) {
            firstResult[k] = testVector[k] * maxValue;
        }
    }
    return  firstResult;
}
