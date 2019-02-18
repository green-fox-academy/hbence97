#include <iostream>
#include <vector>
std::vector<int> vectorMultiplier(std::vector<int> testVector, int testNumber);

int main() {
    std::vector<int> arr = {0, 1, 5, 4};
    int n = 3;
    vectorMultiplier(arr, n);

    return 0;
}

std::vector<int> vectorMultiplier(std::vector<int> testVector, int testNumber)
{
    std::vector<int> result;
//this part of the exercise copies the input vector into an output vector
    result.resize(testVector.size());
    for (int i = 0; i < testVector.size() ; ++i) {
        result[i] = testVector[i];
    }
    //finds the maximum value of the array
    int maxValue = 0;
    for (int j = 0; j < result.size() ; ++j) {
        if(j > maxValue){
            maxValue = result[j];
        }
    }
    for (int k = 0; k <result.size() ; ++k) {
        if((k + 1) % testNumber == 0){
            result[k] = testVector[k] * maxValue;
        }
    }
    return result;
}