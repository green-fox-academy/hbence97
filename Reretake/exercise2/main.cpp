#include <iostream>
#include <vector>
#include <fstream>
#include <map>

std::map<int,int> waterLevel(std::string fileName);
int main() {
    try {           //try,catch ha hiba lenne
        waterLevel("log.txt");
    } catch (std::string s) {
    std::cerr << s << std::endl;
    }
    return 0;
}

std::map<int,int> waterLevel(std::string fileName)
{
    std::ifstream logFile;
    logFile.open(fileName);

    if (!logFile.is_open()) {
        throw "File does not exist!";
    }
    std::string dummy;    //első oszlop amit itt nem kell nézni, az "kuka"
    std::getline(logFile,dummy);

    int dunaLevel;  // oszlopoknak változó
    int tiszaLevel;
    int year;
    std::map<int, int> dunaWaterLevel;  //dunának, tiszának egy map, amiben tárolni fogjuk
    std::map<int, int> tiszaWaterLevel;

    while(logFile >> dunaLevel >> tiszaLevel >> year)  // oszloponként betölti
    {
        dunaWaterLevel[year] = dunaLevel;  //map year-edik oszlopát a dunaLevellel teszi egyenlővé
        tiszaWaterLevel[year] = tiszaLevel;
    }

    int dunaMaxYear = 0;
    int dunaMax = 0;
    int dunaMin = INT32_MAX;
    int dunaMinYear = 0;

    for (std::map<int,int>::iterator it = dunaWaterLevel.begin(); it != dunaWaterLevel.end(); ++it) {  //sima map végig iterálás.
        if (it->second > dunaMax)
        {
            dunaMax = it->second;
            dunaMaxYear = it->first;
        }

        if (it->second < dunaMin)
        {
            dunaMin = it->second;
            dunaMinYear = it->first;
        }
    }
    std::cout << "Duna" << std::endl;
    std::cout << "- lowest " << dunaMinYear << std::endl;
    std::cout << "- highest " << dunaMaxYear << std::endl;
}