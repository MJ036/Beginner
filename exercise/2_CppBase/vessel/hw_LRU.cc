#include <iostream>
#include <list>
#include <unordered_map>
#include <utility>

using std::cout;
using std::endl;
using std::list;
using std::unordered_map;
using std::pair;

class LRU{
public:
    LRU(int cap):_capacity(cap){}

    void put(int key, int value){
        auto it = _cache.find(key);
        if(it != _cache.end()){
            it->second->second = value;
            _nodes.splice(_nodes.begin(),_nodes,it->second);
        }
        else{
            if(_capacity == (int)_nodes.size()){
               auto &deleteNode =  _nodes.back();
               _nodes.pop_back();
               _cache.erase(_cache.find(deleteNode.first));
            }
            _nodes.push_front(pair<int,int>(key,value));
            _cache[key] = _nodes.begin();
        }
    }

    int get(int key){
        auto it = _cache.find(key);
        if(it != _cache.end()){
            _nodes.splice(_nodes.begin(),_nodes,it->second);
            return it->second->second;
        }
        else{
            return -1;
        }
    }

    void print(){
        for(auto &elem : _nodes){
            cout << elem.first << " " << elem.second << " ";
        }
        cout  << endl;
    }


private:
    int _capacity;
    list<pair<int,int>> _nodes;
    unordered_map<int,list<pair<int,int>>::iterator> _cache;
};

void test(){
    LRU lru(4);
    lru.put(1, 10);
    lru.print();

    cout << endl;
    lru.put(2, 20);
    lru.print();

     cout << endl;
    cout << "lru.get(1) = " << lru.get(1) << endl;
    lru.print();
        cout << endl;
    cout << "lru.get(2) = " << lru.get(2) << endl;
    lru.print();

    cout << endl;
    lru.put(3, 30);
    lru.print();

    cout << endl;
    cout << "lru.get(2) = " << lru.get(2) << endl;
    lru.print();

    cout << endl;
    lru.put(3, 33);
    lru.print();

    cout << endl;
    lru.put(4, 40);
    lru.print();

    cout << endl;
    lru.put(5, 50);
    lru.print();

    cout << endl;
    cout << "lru.get(1) = " << lru.get(1) << endl;
    lru.print();









}

int main()
{
    test();
    return 0;
}

