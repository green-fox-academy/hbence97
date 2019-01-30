#include <iostream>
#include <string>
class Sharpie{
    std::string _color;
    float _width;
    float _inkAmount;
public:
    Sharpie(float width, std::string color) {
        _width = width;
        _color = color;

        _inkAmount = 100;
    }

    void use() {
        _inkAmount -=1;
    }


    std::string tostring(){
        std::string stats = "You chosed the color " + _color + " and a " + std::to_string(_width) + "width " + "and after you used it , the ink amount decreased to " + std::to_string(_inkAmount);
        return stats;
    }


};


int main(int argc, char* args[]) {

    Sharpie newSharpie1(2.7, "Blue");

    newSharpie1.use();
    std::cout <<newSharpie1.tostring() << std::endl;


    return 0;
}