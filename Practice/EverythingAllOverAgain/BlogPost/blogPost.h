//
// Created by hegye on 2019. 02. 24..
//

#ifndef BLOGPOST_BLOGPOST_H
#define BLOGPOST_BLOGPOST_H

#include <iostream>

class BlogPost {
    std::string _authorName;
    std::string _title;
    std::string _text;
    std::string _publicationDate;
public:
    BlogPost(std::string authorName, std::string title, std::string text, std::string publicationDate);
    std::string toString();
};


#endif //BLOGPOST_BLOGPOST_H
