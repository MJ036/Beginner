#include <iostream>
#include <string.h>

using namespace std;

class String
{
    String()
        :_pstr(new char[5]() + 4)
    {}

    String &operator=(const String &rhs)
    {
        if(this != &rhs)
        {
            --*(int*)(_pstr - 4);
            if(0 ==*(int*)(_pstr - 4))
            {
                delete [] (_pstr - 4);
            }
            _pstr = rhs._pstr;
            ++*(int*)(_pstr - 4);
        }
    }
private:
    char *_pstr;
};

int main()
{

    return 0;
}
