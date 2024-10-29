#include<iostream>
#include<string.h>

using namespace std;

class String
{
public:
	String():_str(new char[1]()){}

	String(const char *str):_str(new char[strlen(str) + 1]())
    {
        strcpy(_str, str);
    }

	String(const String &rhs):_str(new char[strlen(rhs.c_str())])
    {
        strcpy(_str,rhs.c_str());
    }

	String &operator=(const String &rhs)
    {
        if(this != &rhs)
        {
            delete [] _str;
            _str = new char[strlen(rhs.c_str()) + 1];
            strcpy(_str,rhs.c_str());
        }
        return *this;
    }


	~String()
    {
        if(_str)
        {
            delete [] _str;
            _str = nullptr;
        }
    }

	void print()
    {
        cout << _str << endl;
    }

    size_t length() const
    {
        return strlen(_str);
    }
    const char * c_str() const
    {
        return _str;
    }

private:
	char * _str;
};

void test0(){

	String str1;
	str1.print();
	

	String str2 = "Hello,world";
	String str3("wangdao");
	
	str2.print();		
	str3.print();	
	
	String str4 = str3;
	str4.print();
	
	str4 = str2;
	str4.print();
}

void test1(){
    char p2[] = "hello";
    char *p1 = p2 ;
    cout << p1;
}
int main()
{
	test0();
	return 0;
}
