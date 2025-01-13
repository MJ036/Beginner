#include "mai.h"

using namespace std;
int main()
{
    string expression{ "This is (pezy)." };
    bool bSeen = false;
    stack<char> stk;
    for(auto &num : expression){
        if(num == '('){
            bSeen = true;
            continue;
        }else if(num == ')'){
            bSeen = false;
        }

        if(bSeen){
            stk.push(num);
        }
    }

    string str;
    while(!stk.empty()){
        str += stk.top();
        stk.pop();
    }

    expression.replace(expression.find('(')+1,str.size(),str);
    cout << expression << endl;
    
    return 0;
}
