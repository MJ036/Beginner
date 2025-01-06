#include "mai.h"

using namespace std;

class Debug{
public:
    constexpr Debug(bool b = true):hw(b),io(b),other(b){}
    constexpr Debug(bool b, bool i, bool o):hw(b),io(i),other(o){}

    constexpr bool any(){return hw || io || other;}
    void set_io(bool b) {io = b;};
    void set_hw(bool b) {hw = b;};
    void set_other(bool b) {other = b;};


private:
    bool hw;
    bool io;
    bool other;
};

int main()
{
    return 0;
}

