//
// Created by hegye on 2019. 02. 24..
//

#include "blogPost.h"

BlogPost::BlogPost(std::string authorName, std::string title, std::string text, std::string publicationDate)
{
    _authorName = authorName;
    _title = title;
    _text = text;
    _publicationDate = publicationDate;
}

std::string BlogPost::toString()
{
    return _title + " titled by " + _authorName + " posted at " + _publicationDate + " with a text that goes like " + _text;
}