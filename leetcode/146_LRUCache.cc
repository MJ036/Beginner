#include "mai.h"

using namespace std;

class Node{
public:
    int key,value;
    Node *next,*prev;
    Node(int k = 0, int v = 0) :key(k),value(v){}
};

class LRUCache {
private:
    int capacity;
    Node *dumy;
    unordered_map<int,Node*> key_to_node;

    void remove(Node *x){
        x->prev->next = x->next;
        x->next->prev = x->prev;
    }

    void push_front(Node *x){
        x->prev = dumy;
        x->next = dumy->next;
        x->prev->next = x;
        x->next->prev = x;
    }

    Node *get_node(int key){
        auto it = key_to_node.find(key);
        if(it == key_to_node.end()){
            return nullptr;
        }
        auto node = it->second;
        remove(node);
        push_front(node);
        return node;
    }

public:
    //构造函数：初始化哨兵、容量
    LRUCache(int capacity):capacity(capacity),dumy(new Node()){
        dumy->next = dumy;
        dumy->prev = dumy;
    }
    //获取结点
    int get(int key) {
        auto node = get_node(key);
        return node ? node->value : -1;
    }
    //查key是否存在，如果存在，改值返回。如果不存在，添加，判满处理
    void put(int key, int value) {
        auto node = get_node(key);
        if(node){
            node->value = value;
            return;
        }
        node = new Node(key,value);
        key_to_node[key] = node;
        push_front(node);
        if(key_to_node.size() > capacity){
            auto back_node = dumy->prev;
            key_to_node.erase(back_node->key);
            remove(back_node);
            delete back_node;
        }

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

