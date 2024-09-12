#include "mai.h"

using namespace std;

void test1(){
    vector<int> vec(11,0);
    int score;
    while(cin >> score){
        vec[score/10]++;
    }
    for(auto it : vec){
        cout << it << " ";
    }
}

void test2(){
    vector<int> vec(11,0);
    int score;
    auto it = vec.begin();
    while(cin >> score){
        (*(it + score/10))++;
    }
    for(auto it : vec){
        cout << it << " ";
    }
    cout << endl;

}

int main()
{
    test2();
}

