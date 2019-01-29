#include <iostream>
#include <string>

class Animals{
    int hunger;
    int thirst;

public:
    Animals (){
        hunger =  50;
        thirst = 50;
    }

    void eat(){
        hunger -=1;
    }

    void drink(){
        thirst -= 1;
    }

    void play() {
        hunger += 1;
        thirst += 1;
    }

    std::string tostring(){
        std::string stats = "After the animal ate and drank, his stats decreased to : " + std::to_string(hunger) +  std::to_string(thirst)+ "!" + "after he played with his friends, his stats increased back to " + std::to_string(thirst) ;

        return stats;
    }


};

int main(int argc, char* args[]) {

    Animals catAnimals;
    catAnimals.drink();

    catAnimals.play();
    std::cout << catAnimals.tostring() << std::endl;

}