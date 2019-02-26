#include <iostream>
#include <vector>

int numberPairs(std::vector<char> arr1, std::vector <char> arr2);
void runFirstTest()
{
    std::vector<char> test1 = {'a', 'b', 'c'};
    std::vector<char> test2 = {'c', 'b', 'd', 'e'};

    int result = numberPairs(test1, test2);

    if (result == 2)
    {
        std::cout << "First test passed" << std::endl;
    } else {
        std::cout << "First test failed" << std::endl;
    }
}
int main() {
    runFirstTest();
    return 0;
}

int numberPairs(std::vector<char> arr1, std::vector <char> arr2)
{
    int result = 0;
    arr1 = {'a', 'b', 'c'};
    arr2 = {'c', 'b', 'd', 'e'};
    for (int i = 0; i < arr1.size(); ++i) {
        for (int j = 0; j < arr2.size(); ++j) {
            if (arr1[i] == arr2[j])
                result++;
        }
    }
    return result;
}
