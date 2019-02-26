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

std::map<std::string, int> chipUsageData(std::string fileName)
{
    std::ifstream logFile;
    logFile.open(fileName);

    if(!logFile.is_open())
        throw std::string ("Failed to open file");

    std::map<std::string,int> result;
    std::string line;

    std::string cardNumber;
    //int cardUsage = 0; ( különbség?)


    while(std::getline(logFile,line)){
        std::stringstream lineStream(line);

        std::getline(lineStream,cardNumber,',');
            result[cardNumber]++;//= cardUsage;

    }
    logFile.close();

    return result;
}