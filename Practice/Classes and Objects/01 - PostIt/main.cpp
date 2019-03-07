#include <iostream>
#include <string>
class PostIt {
    std::string backgroundColor;
    std::string text;
    std::string textColor;
public:
    PostIt (std::string a, std::string b, std::string c) {
        backgroundColor = a;
        text = b;
        textColor = c;
    }
    std::string tostring() {

        std::string data = "background color is " + backgroundColor + " text is " + text + " and the color if the text is " +
                textColor;
        return data;


    }
};

int main() {
    PostIt orange ("orange", "Idea 1" , "blue text");
    PostIt pink ("pink", "Awesome", "black text");
    PostIt yellow ("yellow", "Superb!" , "green text");

    std::cout << orange.tostring() << std::endl;
    std::cout << pink.tostring() << std::endl;
    std::cout << yellow.tostring() << std::endl;
    return 0;
}