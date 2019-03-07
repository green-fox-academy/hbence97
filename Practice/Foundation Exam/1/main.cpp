#include <iostream>
#include <vector>
std::vector<int> vectorMultiplier(std::vector<int> testVector, int testNumber);

int main() {
    std::vector<int> arr = {0, 1, 5, 4};
    int n = 3;
    vectorMultiplier(arr, n);
    //std::vector<int> arr2 = vectorMultiplier(arr, n);
    //for (int i = 0; i < arr2.size(); ++i) {
    //    std::cout << arr2[i] << " ";
    //}
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
        if(j > maxValue){       //Hogyha a j-edik elem nagyobb mint az eddigi maxValue, akkor a j-edik (talált) elem értéke lesz az uj maxValue.
            maxValue = result[j];       //Majd folytatja a keresését, amig végig nem ér a vector size-ján
        }
    }
    //minden n-edik elemet beszorozza a maxValue-val.
    for (int k = 0; k <result.size() ; ++k) {
        if((k + 1) % testNumber == 0){
            result[k] = testVector[k] * maxValue;
        }
    }
    return result;
}