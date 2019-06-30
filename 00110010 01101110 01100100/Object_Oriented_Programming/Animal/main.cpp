#include <iostream>

class Animal{
public:
    Animal(std::string animalType){
        _hunger = 50;
        _thirst = 50;
    };
    int eat(){
      _hunger -= -1;
    };
    int drink(){
        _thirst -= -1;
    };
    int play(){
        _hunger += 1;
        _thirst += 1;
    };
    std::string toString() {
        std::string info = " has a hunger value of " + std::to_string(_hunger) + ". And  a thirst value of " + std::to_string(_thirst);
        return info;
    }

private:
    int _hunger;
    int _thirst;
};

int main() {

    Animal animal1("Dog");
    animal1.play();
    Animal animal2("Monkey");

    std::cout << "The dog" << animal1.toString() << std::endl;
    std::cout << "The monkey" << animal2.toString() << std::endl;

    return 0;
}