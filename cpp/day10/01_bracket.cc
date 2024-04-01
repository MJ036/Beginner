#include <iostream>
#include <string.h>

using namespace std;

class CharArry
{
public:
    CharArry(size_t sz = 10)
        :_sz(sz)
         ,_data(new char[_sz]())
    {
        cout << "CharArry(size_t sz = 10)" << endl;
    }
    
    char &operator[](size_t idx)
    {
        cout << "char &operator[](size_t)" << endl;
        if(idx < size())
        {
            return _data[idx];
        }
        else
        {
            static char charnull = '\0';
            return charnull;
        }
    }

    size_t size() const
    {
        return _sz;
    }
    
    ~CharArry()
    {
        cout << "~CharArry()" << endl;
        if(_data)
        {
            delete  []_data;
            _data = nullptr;
        }
    }

private:
    int _sz;
    char *_data;
};

void test()
{
    const char *pstr = "hello";
    CharArry ca(strlen(pstr) + 1);

    for(size_t idx = 0; idx != ca.size(); ++idx)
    {
       // ca[idx] = pstr[idx];
       ca.operator[](idx) = pstr[idx];
    }
    cout << endl;

    for(size_t idx = 0; idx != ca.size(); ++idx)
    {
        cout << ca[idx] << " ";
    }
    cout << endl;
}

int main()
{
    test();
    return 0;
}

