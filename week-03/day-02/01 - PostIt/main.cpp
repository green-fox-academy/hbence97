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
 PostIt orangePostIt ("orange", "Idea 1", "blue text");
 PostIt pinkPostIt ("pink", "Awesome", "black text");
 PostIt yellowPostIt ("yellow", "Superb!", "green text");

 std::cout << pinkPostIt.tostring() << std::endl;
 std::cout << orangePostIt.tostring() << std::endl;
 std::cout << yellowPostIt.tostring() << std::endl;
}