#include "mai.h"
using namespace std;


class Book{
public:
    Book(std::string isbn , std::string author):_isbn(isbn),_author(author){}
    Book():Book("unknow","unknow"){}
private:
    std::string _isbn;
    std::string _author;
friend ostream& operator<<(ostream& os, const Book& book);
};
ostream& operator<<(ostream& os, const Book& book){
    os << book._isbn << book._author;
    return os;
}


int main()
{
    return 0;
}

