#include <iostream>
#include <string>
class PostIt {
public:
    PostIt(std::string backgroundColor, std::string text, std::string textColor){
        _backgroundColor = backgroundColor;
        _text = text;
        _textColor = textColor;
    }
    std::string tostring() {
        std::string data = "background color: " + _backgroundColor + ", Text: " + _text + ", text color: " + _textColor;
        return data;
    }
private:
    std::string _text;
    std::string _textColor;
    std::string _backgroundColor;
};

int main()
{
	PostIt postIt1("Orange", "Idea 1", "Blue");
	std::cout << postIt1.tostring() << std::endl;

	PostIt postIt2("Pink", "Awesome", "Black");
    std::cout << postIt2.tostring() << std::endl;

    PostIt postIt3("Yellow", "Superb", "Green");
    std::cout << postIt3.tostring() << std::endl;

    return 0;
}