#include <iostream>
#include <queue>
#include <vector>

using std::cout;
using std::endl;
using std::priority_queue;
using std::vector;

void test(){
    vector<int> vec = {1, 3, 5, 7, 4, 3, 2, 6};
    
    priority_queue<int> pque;
    for(size_t idx = 0; idx != vec.size(); ++idx){
        pque.push(vec[idx]);
        cout << "priority biggest" << pque.top() << endl;
    }

    while(!pque.empty()){
        cout << pque.top() << " ";
        pque.pop();
    }
    cout << endl;
}

int main()
{
    test();
    return 0;
}

