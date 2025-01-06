#include "mai.h"

using namespace std;

struct Person{
public:
    Person() = default;
    Person(const string& n,const string& a):name(n),adress(a){}
    explicit Person(std::istream& is){read(is,*this);}

    string getName()const{
        return name;
    }
    string getAdress()const{
        return adress;
    }
private:
    string name;
    string adress;
friend istream& read(istream& is, Person& rhs);
friend Person print(ostream& os,const Person& rhs);
};

istream& read(istream& is, Person& rhs){
    is >> rhs.name >> rhs.adress;
    return is;
}

Person print(ostream& os,const Person& rhs){
    Person per = rhs;
    os << per.name << " " << per.adress;
    return per;
}

int main()
{
    Person per("mai","houshazhaung");
    print(cout,per);
    cout << endl;
    read(cin,per);
    print(cout,per);
    cout << endl;

    return 0;
}

