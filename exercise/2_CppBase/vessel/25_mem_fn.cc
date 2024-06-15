#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using std::cout;
using std::endl;
using std::vector;
using std::for_each;
using std::mem_fn;
using std::remove_if;
using std::bind;

class Number{
public:
    Number(size_t data = 0):_data(data){}

    void print(){
        cout << _data << " ";
    }

    bool isEven(){
        return (_data % 2 == 0);
    }

    bool isPrimer(){
        if(1 == _data){
            return false;
        }
        for(size_t idx = 2; idx <= _data/2; idx++){
            if(_data % idx == 0){
                return false;
            }
        }
        return true;
    }


private:
    size_t _data;
};

void test(){
    vector<Number> vec;
    for(size_t idx = 1; idx != 30; ++idx){
        vec.push_back(Number(idx));
    }

    Number num(10);
    /* for_each(vec.begin(),vec.end(),mem_fn(&Number::print)); */
    using namespace std::placeholders;
    for_each(vec.begin(),vec.end(),bind(&Number::print,_1));
    
    cout << endl;
    vec.erase(remove_if(vec.begin(),vec.end(),mem_fn(&Number::isEven)),vec.end());

    for_each(vec.begin(),vec.end(),mem_fn(&Number::print));
    cout << endl;

    vec.erase(remove_if(vec.begin(),vec.end(),mem_fn(&Number::isPrimer)),vec.end());

    for_each(vec.begin(),vec.end(),mem_fn(&Number::print));
    cout << endl;


}

int main()
{
    test();
    std::cout << "Hello world" << std::endl;
    return 0;
}

