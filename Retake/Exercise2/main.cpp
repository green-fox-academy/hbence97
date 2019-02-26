#include <iostream>
#include <map>
#include <fstream>
#include <sstream>

int main() {

    return 0;
}

std::map<std::string, int> chipUsageData(std::string fileName)
{
    std::map<std::string,int> result;

    std::ifstream logFile;
    logFile.open(fileName);

    if(!logFile.is_open())
        throw std::string ("Failed to open file");
    std::string line;
    while(std::getline(logFile,line)){
        std::stringstream stringstream;
        std::string ChipUsageData;
        std::getline(line,ChipUsageData,', ');

    }
}