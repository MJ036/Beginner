#include <iostream>
#include <functional>
#include <vector>
#include <string>


using std::cout;
using std::endl;
using std::function;
using std::vector;
using std::string;

vector<function<void(const string &)>> vec;
function<void(const string&)> f;

int main()
{
    int num = 10;
    string name("wangdao");
    vec.push_back([&num,&name](const string &value){
                  cout << "num = " << num << endl;
                  cout << "name = " << name << endl;
                  cout << "value = " << value << endl;
                  });
    std::cout << "Hello world" << std::endl;

    for(auto f: vec){
        f("hello");
    }
    return 0;
}

