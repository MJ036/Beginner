#include "mai.h"


class Book{
public:
    Book(std::string isbn , std::string author):_isbn(isbn),_author(author){}
    Book():Book("unknow","unknow"){}
private:
    std::string _isbn;
    std::string _author;

};


int main()
{
    return 0;
}

