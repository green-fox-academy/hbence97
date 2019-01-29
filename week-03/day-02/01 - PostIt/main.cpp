#include <iostream>
#include <string>

class PostIt{
public:
    PostIt (std::string a, std::string b, std::string c) {
        backgroundColor = a;
        text = b;
        textColor = c;

    }

    std::string tostring () {
      std::string data = "background color: " + backgroundColor + ", Text: " + text + ", text color: " + textColor;
      return data;

    };

private:
    std::string backgroundColor;
    std::string text;
    std::string textColor;

};

int main(int argc, char* args[]) {
 PostIt orangePostit ("orange", "Idea 1", "blue text");
 PostIt pinkPostit ("pink", "Awesome", "black text");
 PostIt yellowPostit ("yellow", "Superb!", "green text");

 std::cout << pinkPostit.tostring() << std::endl;
 std::cout << orangePostit.tostring() << std::endl;
 std::cout << yellowPostit.tostring() << std::endl;
}