#include <iostream>
#include <string>

class PostIt{

    std::string backgroundColor;
    std::string text;
    std::string textColor;
public:
    PostIt( std::string a, std::string b, std::string c){
        backgroundColor = a;
        text = b;
        textColor = c;
    }
    std::string tostring() {

        std::string info =
                "The background color is " + backgroundColor + " The text is " + text + " and the text color is " +
                textColor;
        return info;
    }

};
int main()
{
    PostIt orangeinfo ("Orange ", "Idea 1 ", "Blue text");

    std::cout << orangeinfo.tostring() << std::endl;

    return 0;
}