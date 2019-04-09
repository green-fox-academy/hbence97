//
// Created by hegye on 2019. 02. 24..
//

#ifndef POSTIT_POSTIT_H
#define POSTIT_POSTIT_H


#include <iostream>

class PostIt {
    std::string _backgroundColor;
    std::string _text;
    std::string _textColor;
public:
    PostIt(std::string backgroundColor, std::string text, std::string textColor);
    std::string toString();
};


#endif //POSTIT_POSTIT_H
