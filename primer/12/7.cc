#include "mai.h"
#include <memory>
#include <vector>
using namespace std;

shared_ptr<vector<int>> a(){
    return make_shared<vector<int>>();
}

shared_ptr<vector<int>> b(shared_ptr<vector<int>> p){
    int temp;
    while(cin >> temp){
        p->push_back(temp);
    }
    return p;
}

void c(shared_ptr<vector<int>> vec){
    for(auto num : *vec){
        cout << num << " ";
    }
    cout << endl;
    
}

int main()
{
    shared_ptr<vector<int>>p = a();
    b(p);
    c(p);
    return 0;
}

