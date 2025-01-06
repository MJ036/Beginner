#include "mai.h"

using namespace std;

class X;
class Y;

class X{
    Y* _y;
};
class Y{
    X* _x;
};

int main()
{
    return 0;
}

