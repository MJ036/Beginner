#include "mai.h"
#include <functional>
using namespace std;

int main()
{
    plus<int> add;
    minus<int> sub;
    multiplies<int> mul;
    divides<int> div;

    map<char,function<int(int,int)>> binops = {
        {'+',[&](int a, int b){ return add(a,b); }},
        {'-',[&](int a, int b){ return sub(a,b); }},
        {'*',[&](int a, int b){ return mul(a,b); }},
        {'/',[&](int a, int b){ return div(a,b); }}
    };

    int a, b;
    char c;
    cin >> a >> c >> b;
    cout << "\n" << binops[c](a,b) << endl;


    return 0;
}

