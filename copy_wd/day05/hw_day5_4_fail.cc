#include<iostream>
#include<string.h>

using namespace std;

class String
{
public:
	String()
    {
        _pstr = nullptr;
    }

	String(const char *pstr)
    {
        strcpy(_pstr, pstr);
    }

	String(const String &rhs)
    {
        strcpy(_pstr,rhs._pstr);
    }

	String &operator=(const String &rhs)
    {
        this->_pstr = rhs._pstr;
        return *this;
        
    }

	~String()
    {

    }

	void print()
    {
        cout << _pstr << endl;
    }

    size_t length() const
    {
        return strlen(_pstr);
    }
    const char * c_str() const
    {
        return _pstr;
    }

private:
	char * _pstr;
};

int main()
{
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
	
	return 0;
}
