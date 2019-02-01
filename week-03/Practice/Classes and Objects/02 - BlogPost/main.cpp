#include <iostream>
#include <string>
class BlogPost {
    std::string authorName;
    std::string title;
    std::string text;
    std::string publicationDate;
public:
    BlogPost (std::string a, std::string b, std::string c, std::string d){
        authorName = a;
        title = b;
        text = c;
        publicationDate = d;

    }

    std::string tostring() {
        std::string info = "The authors name is " + authorName + "the title is " + title + " the text says " + text + "with a publication date of " + publicationDate;
        return info;
    }

};

int main() {
    BlogPost aBlogSpot ("John Doe", "Lorem Ipsum", "Lorem ipsum dolor sit amet.", "2000.05.04.");
    BlogPost bBlogSpot ("Tim Urban", "Wait,but why?", "A popular long-form, stick-figure-illustrated blog about almost everything.", "2010.10.10");

    std::cout << aBlogSpot.tostring() << std::endl;
    std::cout << bBlogSpot.tostring() << std::endl;
    return 0;
}