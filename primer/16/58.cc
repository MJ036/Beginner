#include "mai.h"
#include"../shared/StrVec.h"
using namespace std;


int main(){
    StrVec strvec;
    strvec.emplace_back(string("mai"));
    for(auto n : strvec){
        cout << n << endl;
    }

}
