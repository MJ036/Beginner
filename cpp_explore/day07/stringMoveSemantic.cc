#include <string.h>
#include <iostream>

using namespace std;

class String
{
public:
    String()
        :_pstr(nullptr)
    {
        cout << "String()" << endl;
    }
    String(const char *pstr)
        :_pstr(new char[strlen(pstr) + 1]())
    {
        cout << "String(const char *)" << endl;
        strcpy(_pstr,pstr);
    }

    String(const String &rhs)
        :_pstr(new char[strlen(rhs._pstr) + 1]())
    {
        cout << "String(const String &)" << endl;
        strcpy(_pstr,rhs._pstr);
    }

    String &operator=(const String &rhs)
    {
        cout << "String &operator=(const String &)" << endl;
        if(this != &rhs){
            delete [] _pstr;
            _pstr = nullptr;
            _pstr = new char[strlen(rhs._pstr) + 1]();
            strcpy(_pstr,rhs._pstr);
        }
        return *this;
    }

    String(String &&rhs)
        :_pstr(rhs._pstr)
    {
        cout << "String(String &&)" << endl;
        rhs._pstr = nullptr;
    }

    String &operator=(String &&rhs)
    {
        cout << "String &operator=(String &&)" << endl;
        if(this != &rhs)
        {
            delete [] _pstr;
            _pstr = nullptr;

            _pstr = rhs._pstr;
            rhs._pstr = nullptr;

        }
        return *this;
    }

    ~String()
    {
        cout << "~String()" << endl;
        if(_pstr){
            delete [] _pstr;
            _pstr = nullptr;
        }
    }

    friend std::ostream &operator<<(std::ostream &os, const String &rhs);

private:
    char * _pstr;


};

    std::ostream &operator<<(std::ostream &os,const String &rhs)
    {
        if(rhs._pstr){
            os << rhs._pstr;
        }
        return os;
    }

void test()
{
    String s3 = "world";
    cout << "s3 =" << s3 << endl;

    String s2;
    cout << endl;
    s2 = String("world");
    cout << "s2 = " << s2 << endl;

    s2 = std::move(s2);
    cout << "s2 = " << s2 << endl;
}

const int cx =10;
void test2()
{
    const int cy = 20;
    int c = 10;
    const char *pstr = "world";
    printf("&cx = %p\n", &cx);
    printf("&c = %p\n", &c);
    printf("&cy = %p\n", &cy);
    printf("&pstr = %p\n", &pstr);
    printf("pstr = %p\n", pstr);

}

int main()
{
    
test2();
    return 0;
}

