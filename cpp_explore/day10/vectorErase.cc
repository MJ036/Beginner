#include <iostream>
#include <vector>

using namespace std;

void test(){
    vector<int> number = {1,2,5,5,5,3,5,5,8};

    for(auto it = number.begin(); it != number.end(); ++it)
    {
        cout << *it << " ";
    }
    
    cout << endl << "delete----------------------" << endl;
    for(auto it = number.begin(); it != number.end();){
        if(5 == *it)
        {
            number.erase(it);
        }
        else{
            ++it;
        }
    }
    
    for(auto &elem : number){
        cout << elem << " ";
    }
    cout << endl;
}


int main()
{
    test();
    return 0;
}

