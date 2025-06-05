#include "mai.h"
#include "debug_rep.h"
#include "print.h"
using namespace std;

template<typename... Args>
ostream& errorMsg(ostream &os, const Args& ...rest){
    return print(os,debug_rep(rest)...);
}

int main(){
    errorMsg(cout,"mai","jia",string("bao"));
}


