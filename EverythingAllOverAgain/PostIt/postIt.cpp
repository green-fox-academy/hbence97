//
// Created by hegye on 2019. 02. 24..
//

#include "postIt.h"

PostIt::PostIt(std::string backgroundColor, std::string text, std::string textColor){
    _backgroundColor = backgroundColor;
    _text = text;
    _textColor = textColor;
}

std::string PostIt::toString()
{
    return "The text color is: " + _textColor + "the text is: " + _text + " and the background color is: " + _backgroundColor;
}