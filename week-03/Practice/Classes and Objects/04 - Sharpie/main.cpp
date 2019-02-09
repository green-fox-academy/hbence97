#include <iostream>
#include <string>
class Sharpie{
    std::string color;
    float width;
    float inkAmount;

public:
    Sharpie(std::string a, float b){
        color = a;
        width = b;
        inkAmount = 100;
    }
    void use(){
        inkAmount = inkAmount-1;
    }

    std::string tostring(){
        std::string info = "color is " + color + " and the width is " + std::to_string(width) + "and the ink amount is" + std::to_string(inkAmount);
        return info;
    }
};

int main()
{
    Sharpie pinkSharpie("pink", 2.7);
    pinkSharpie.use();

    std::cout << pinkSharpie.tostring() << std::endl;
    return 0;
}