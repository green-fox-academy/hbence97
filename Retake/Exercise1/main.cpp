#include <iostream>
#include <vector>
int hammingDist(std::string test1, std::string test2);
std::vector<std::string> list(std::string input, std::vector<std::string> listOfWords);

void runFirstTest()
{
    std::string testInput = "apple";
    std::vector<std::string> testListOfWords = {"apple", "apply", "tuple", "alter"};

    std::vector<std::string> result = list(testInput, testListOfWords);
    std::vector<std::string> expectedResult = {"apple", "apply", "tuple"};
    if(result == expectedResult) {
        std::cout << "The test was good" << std::endl;
    }
}
int main() {
    runFirstTest();
    return 0;
}

/*int hammingDist(std::string test1, std::string test2)
{
    int distance = 0;
    for (int i = 0; i < test1.size(); ++i) {
        if(test1[i] != test2[i])
            distance++;
    }
    return distance;
}
*/
std::vector<std::string> list(std::string input, std::vector<std::string> listOfWords) {
    std::vector<std::string> result;
    for (int i = 0; i < listOfWords.size(); i++) {
        std::string word = listOfWords[i];
    int difference = 0;
    for (int j = 0; j < input.size(); ++j) {
        if (input[j] != word[j]) {
            difference++;
        }
    }
    if (difference <= 3)
        result.push_back(word);
    }
    return result;
}