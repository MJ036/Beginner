#include "mai.h"

using namespace std;

class Node{
public:
    int _key,_value;
    Node *next,*prev;
    Node(int key = 0, int value = 0):_key(key),_value(value){}
};

class LRUCache {
private:
    int _capacity;
    Node *_dumy;
    unordered_map<int,Node*> _key_to_node;

    void remove(Node *node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void push_front(Node *node){
        node->next = _dumy->next;
        node->prev = _dumy;
        _dumy->next->prev = node;
        _dumy->next = node;
    }

    Node *get_node(int key){
        auto it =  _key_to_node.find(key);
        if(it == _key_to_node.end()){
            return nullptr;
        }
        auto node = it->second;
        remove(node);
        push_front(node);
        return node;
    }


public:
    LRUCache(int capacity):_capacity(capacity),_dumy(new Node()){
        _dumy->next = _dumy;
        _dumy->prev = _dumy;
    }

    int get(int key) {
        auto node = get_node(key);
        return node ? node->_value : -1;
    }

    void put(int key, int value) {
        auto node = get_node(key);
        if(node){
            node->_value = value;
            return;
        }
        node = new Node(key,value);
        _key_to_node[key] = node;
        push_front(node);
        if(_key_to_node.size() > _capacity){
            auto back_node = _dumy->prev;
            _key_to_node.erase(back_node->_key);
            remove(back_node);
        }
    }
};


