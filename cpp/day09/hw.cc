#include <iostream>
#include <string.h>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class String
{
public:
    String():_pstr(new char[1]())
    {
        cout << "String()" << endl;
    }

    //String s1 ("hello")
    //String s1 = "hello"
    String(const char *pstr):_pstr(new char[strlen(pstr) + 1]())
    {
        cout << "String(const char *)" << endl;
        strcpy(_pstr,pstr);
    }
    
    //String s2 (s1);
    //String s2 = s1;
    String(const String &rhs)
    {
        cout << "String(const String &)" << endl;
        strcpy(_pstr,rhs._pstr);
    }
    
    ~String()
    {
        cout << "~String" << endl;
        if(_pstr){
            delete [] _pstr;
            _pstr = nullptr;
        }
    }

    //String s1;
    
    //s1 = s2;
    String &operator=(const String &rhs){
        cout << "String &operator=(const String &)" << endl;
        if(this != &rhs){
            delete [] _pstr;
            _pstr = nullptr;
            
            _pstr = new char[strlen(rhs._pstr) + 1]();
            strcpy(_pstr,rhs._pstr);
        }
        return *this;
    }

    //s1 = "hello";
    String &operator=(const char * pstr){
        cout << "String &operator=(const char *)" << endl;
        String tmp(pstr);       //tmp对象接收字符串
        *this = tmp;        //用tmp把字符串传递给this所指对象
        return *this;       //这么做省去了 对对象的成员的访问
    }

    // s1 += s2;
    String &operator+=(const String &rhs){
        cout << "String &operator+=(const String &)" << endl;
        String tmp;
        if(tmp._pstr)
        {
            delete [] tmp._pstr;    //申请的对象成员，指向未知，故删除
        }
        tmp._pstr = new char[strlen(_pstr) + 1]();
        strcpy(tmp._pstr,_pstr);
        delete [] _pstr;
        _pstr = nullptr;
        _pstr = new char[strlen(tmp._pstr) + strlen(rhs._pstr) + 1]();
        strcpy(_pstr,tmp._pstr);
        strcat(_pstr,rhs._pstr);

        return *this;
    }
    
    //s1 += "hello"
    String &operator+=(const char *pstr)
    {
        cout << "String &operator+=(const char*)" << endl;
        String tmp(pstr);
        *this += tmp;
        return *this;
    }
    
private:
    char * _pstr;
};

int main()
{

    return 0;
}

