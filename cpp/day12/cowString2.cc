#include <iostream>
#include <string.h>

using namespace std;

class String
{
public:
    String()
        :_pstr(new char[5]() + 4)
    {
        *(int *)(_pstr - 4) = 1;
    }
        
    String(const char *pstr)
        :_pstr(new char[strlen(pstr) + 5]() + 4)
    {
        strcpy(_pstr,pstr);
        *(int *)(_pstr - 4) = 1;

    }

    String(const String &rhs)
        :_pstr(rhs._pstr)
    {
        ++*(int*)(_pstr - 4);
    }

    String &operator=(const String &rhs)
    {
        --*(int*)(_pstr - 4);
        if(0 == *(int*)(_pstr - 4))
        {
            delete [] (_pstr -4);
        }

        _pstr = rhs._pstr;
        ++*(int*)(_pstr - 4);
        return *this;
    }

    char &operator[](size_t idx)
    {
        if(idx < size())
        {
            if(getRefConst() > 1)
            {
                char *ptmp = new char[size() + 5]() + 4;
                strcpy(ptmp,_pstr);
                --*(int*)(_pstr - 4);

                _pstr = ptmp;
                *(int *)(_pstr - 4) = 1;
            }
            return _pstr[idx];
        }
        else
        {
            static char charnull = '\0';
            return charnull;
        }
    }

    ~String()
    {
        --*(int*)(_pstr - 4);
        if(0 == *(int*)(_pstr - 4))
        {
            delete [] (_pstr -4);
        }

    }
    
    const char *c_str() const
    {
        return _pstr;
    }

    int getRefConst() const
    {
        return *(int*)(_pstr - 4);
    }

private:
    char *_pstr;
    
    size_t size() const
    {
        return strlen(_pstr);
    }

};

int main()
{

    return 0;
}

