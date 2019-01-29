#include <iostream>
#include <string>
class BlogPost{
    private:
    std::string authorName;
    std::string title;
    std::string text;
    std::string publicationDate;


public:
    BlogPost (std::string authorName, std::string title, std::string text, std::string publicationDate){
        this->authorName = authorName;
        this->title = title;
        this->text = text;
        this->publicationDate = publicationDate;
    }

    std::string tostring(){
        std::string info = "The book " + title + "was published on " + publicationDate + "by " + authorName + "with a text that goes like" + text;

        return info;

    }
};


int main(int argc, char* args[]) {

    BlogPost loremipsumBlogPost ("Lorem Ipsum ","2000.05.04 ","John Doe ","Lorem ipsum dolor sit amet" );
    BlogPost waitbutwhyBlogPost ("Wait but why ","2010.10.10 ","Tim Urban ","A popular long-form, stick-figure-illustrated blog about almost everything.");
    BlogPost oneenginerBlogPost ("One Enginer Is Trying to Get IBM to Reckon With Trump ", "2017.03.28 ","William Turton ","Daniel Hanley, a cybersecurity engineer at IBM, doesn't want to be the center of attention. When I asked to take his picture outside one of IBM’s New York City offices, he told me that he wasn't really into the whole organizer profile thing.");

    std::cout << loremipsumBlogPost.tostring() << std::endl;
    std::cout << waitbutwhyBlogPost.tostring() << std::endl;
    std::cout << oneenginerBlogPost.tostring() << std::endl;

}