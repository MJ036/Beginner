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
    
    char &operator[](std::size_t index)
    {
        if(index < size())
        {
            return _pstr[index];
        }
        else{
            static char nullchar  = '\0';
            return nullchar;
        }
    }

    std::size_t size() const{
        return strlen(_pstr);
    }

    const char* c_str() const{
        return _pstr;
    }

    friend bool operator==(const String &,const String &);
    friend bool operator!=(const String &,const String &);
    
    friend bool operator<(const String &,const String &);
    friend bool operator>(const String &,const String &);
    friend bool operator<=(const String &,const String &);
    friend bool operator>=(const String &,const String &);

    friend std::ostream &operator<<(std::ostream &os,const String &s);
    friend std::istream &operator>>(std::istream &is, String &s);

private:
    char * _pstr;
};

bool operator==(const String &lhs,const String &rhs)
{
    return !strcmp(lhs._pstr,rhs._pstr);
}

bool operator!=(const String &lhs,const String &rhs)
{
    return strcmp(lhs._pstr,rhs._pstr);
}

bool operator>(const String &lhs,const String &rhs)
{
    return strcmp(lhs._pstr,rhs._pstr) > 0;
}

bool operator<(const String &lhs,const String &rhs)
{
    return strcmp(lhs._pstr,rhs._pstr) < 0;
}

bool operator>=(const String &lhs,const String &rhs)
{
    return strcmp(lhs._pstr,rhs._pstr) >= 0;
}

bool operator<=(const String &lhs,const String &rhs)
{
    return strcmp(lhs._pstr,rhs._pstr) <= 0;
}

std::ostream &operator<<(std::ostream &os, const String &rhs)
{
    if(rhs._pstr){
        os << rhs._pstr;
    }

    return os;
}

std::istream &operator>>(std::istream &is, String &rhs)
{
    if(rhs._pstr){
        delete [] rhs._pstr;
        rhs._pstr = nullptr;
    }
    
    vector<char> buffer;
    char ch;
    while((ch = is.get()) != '\n')
    {
        buffer.push_back(ch);
    }

    rhs._pstr = new char[buffer.size() + 1]();
    strncpy(rhs._pstr,&buffer[0], buffer.size());

    return is;

}

String operator+(const String &lhs,const String &rhs)
{
    cout << "String operator+(const String &, const String &)" << endl;
    String tmp(lhs);
    tmp += rhs;

    return tmp;
}

String operator+(const String &lhs, const char *pstr)
{
    cout << "String operator+(const String &lhs, const char *pstr)" << endl;
    String tmp(lhs);
    tmp += pstr;
    return tmp;
}

String operator+(const char *pstr,const String &rhs)
{
    cout << "String operator+(const char *, const String &)" << endl;
    String tmp(pstr);
    tmp += rhs;
    return tmp;
}

void test(){
    String s1;
    cout << "s1 = " << s1 << endl;

    String s2 = "hello";
    cout << "s2 = " << s2 << endl;

    //s2 = "world" error 类型不匹配
    
    String s3 = "mai";
    s3 += "jia";
    cout << "s3 = " << s3 << endl;

}

void test1(){
    int *pint = nullptr;
    cout << "pint:" << pint << endl;
    cout << "over" << endl;

    char *pstr = nullptr;     
    cout << "pstr:" << pstr << endl;    //会崩溃
    cout << "over" << endl;
}



int main()
{
    test();
    cout << endl;
    test1();
    return 0;
}



