#include <iostream>
#include <string>
class Animal{
    int hunger;
    int thirst;
public:
    Animal() {
        hunger = 50;
        thirst  = 50;
    }
    void eat(){
        hunger -= 1;
    }

    void drink() {
        thirst -= 1;
    }


    std::string tostring(){
        std::string info = "after this animal ate, his hunger decreases to " + std::to_string(hunger) + "after he drank, his thirst decreased to " + std::to_string(thirst);
        return info;
    }

};
int main() {
        Animal aAnimal;
        aAnimal.eat();

        std::cout << aAnimal.tostring() << std::endl;

    return 0;
}