#include "mai.h"
#include <vector>
using namespace std;

vector<int>* a(){
    return new vector<int>();
}

vector<int>* b(vector<int>* p){
    int temp;
    while(cin >> temp){
        p->push_back(temp);
    }
    return p;
}

void c(vector<int>* vec){
    for(auto num : *vec){
        cout << num << " ";
    }
    cout << endl;
    
}

int main()
{
    vector<int>*p = a();
    b(p);
    c(p);
    delete p;
    return 0;
}

