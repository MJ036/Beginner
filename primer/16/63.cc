#include "mai.h"
using namespace std;

template<typename T>
int test_find(const vector<T> &vec, T val){
    int count = 0;
    for(auto v : vec){
        if(v == val){
            count++;
        }
    }
    return count;
}

template<>
int test_find(const vector<const char*>& vec,const char* val){
    cout << "template<>" << endl;
    int count = 0;

    auto iter = vec.begin();

    do{
        iter = std::find(iter,vec.end(),val);
        if(iter != vec.end()){
            ++count;
            ++iter;
        }
    }while(iter != vec.end());
    return count;
}

int main(){
    vector<double> vec_d{1.0,2.0,3.0,5.0,1.0};
    vector<int> vec_i{1,2,3,4,5,6,7,7,7};
    vector<string> vec_s{"mai","jia","bao","shuai","shuai"};
    vector<const char*> vec_c{"mai","jia","bao","shuai","shuai"};

    cout << "double: " << test_find(vec_d,1.0) << endl;
    cout << "int: " << test_find(vec_i,7) << endl;
    cout << "string: " << test_find(vec_s,string("shuai")) << endl;
    cout << "cosnt char* : " << test_find(vec_c,"shuai") << endl;

}
