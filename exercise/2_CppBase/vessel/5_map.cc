#include <iostream>
#include <map>
#include <string>
#include <utility>

using namespace std;

template <typename Container>
void display(const Container &con)
{
    for(auto &elem : con)
    {
        cout << elem.first << "  " << elem.second << endl;
    }
}

void test_map(){
    map<int,string> number = {
        {1,"bejing"},
        {19,"beijing"},
        pair<int,string>(3,"nanjing"),
        make_pair(4,"wuhan"),
        make_pair(19,"wuhan"),
    };
    display(number);

    cout << endl << "map查找操作" << endl;
    size_t cnt = number.count(8);
    cout << "cnt = " << cnt << endl;

    auto it = number.find(7);
    if(it == number.end())
    {
        cout << "该元素不在map中" << endl;
    }
    else
    {
        cout << "该元素存在map中 " << it->first 
             << "    " << it->second << endl; 
    }

    cout << "insert" << endl;
    auto ret = number.insert(make_pair(5,"dongjing"));
    if(ret.second){
        cout << "inserted successfully" << ret.first->first << " " << ret.first->second << endl;
    }
    else{
        cout << "inserted failedly" << endl;
    }
    display(number);

    cout << endl << "map的下标操作" << endl;
    cout << "number[1] = " << number[1] << endl;//查找
    cout << "number[8] = " << number[8] << endl;
    display(number);    

    cout << endl;
    //T &operator[](const Key &)
    number[8] = "hainan";//修改
    number[10] = "hainan";
    display(number);

    map<int,string> mm = {{1,"wuhan"}};
    cout << "mm[1] = " << mm[1]  << endl;



}

int main()
{
    test_map();   
    return 0;
}

