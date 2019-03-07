#include <iostream>
#include <map>
#include <fstream>
#include <sstream>

std::map<std::string, int> chipUsageData(std::string fileName);

int main() {
    try {
        std::map<std::string, int> chipUsage = chipUsageData("logs.csv");

        //Print the result
        for (std::map<std::string, int>::iterator it = chipUsage.begin(); it != chipUsage.end(); ++it) {
            std::cout << it->first << " - " << it->second << std::endl;
        }
    } catch (std::string e) {
        std::cout << e << std::endl;
    }
    return 0;
}

std::map<std::string, int> chipUsageData(std::string fileName) {
    std::ifstream logFile;
    logFile.open(fileName);

    if (!logFile.is_open())
        throw std::string("Failed to open file");

    std::map<std::string, int> result;

    std::string line;

    while (std::getline(logFile, line)) {
        std::stringstream lineStream(line);
        int counter = 0;
        std::string entranceName;
        std::string cardNumber;

        std::string data;
        while(std::getline(lineStream, data, ',')) {
            if (counter == 5) {
                entranceName = data;
            }
            if (counter == 12){
                cardNumber = data;
            }
            counter++;
        }
        if(entranceName == "A66 - 04 FÕBEJÁRAT (F-1) Door #1" ) {
            result[cardNumber]++;
        }
    }
    logFile.close();

    return result;
}