#include "mai.h"

using namespace std;

int main()
{
    vector<string> text={"mai","","jia","bao"};
    auto beg = text.begin(),end = text.end();
    auto mid = beg + (end-beg)/2;

    return 0;
}

