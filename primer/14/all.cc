#include "mai.h"
#include <algorithm>
#include <cstdlib>
using namespace std;

class PrintString{
public:
    //35
//    string operator()(istream &is){
//        string line;
//        if(getline(is,line)){
//            return line;
//        }else{
//            return string();
//        }
//    }
    //36
    void operator()(istream &is,vector<string>& v){
        string line;
        while(getline(is,line)){
            v.push_back(line);
        }
    };
};

class IsEqual{
    int value;
public:
    IsEqual(int v ):value(v){}
    bool operator()(int elem){
        return elem == value;
    }
};
void test_36(){
    PrintString p;
    vector<string> v;
    p(cin,v);
    for(auto & l : v){
        cout << l << endl;
    }
}

void test_37(){
    vector<int> vec  = {1,1,3,3,5,5,6,6};
    replace_if(vec.begin(),vec.end(),IsEqual(3),5);
    	for (int i : vec) std::cout << i << " ";
	std::cout << std::endl;
}

int main()
{
    test_37();
    return 0;
}

