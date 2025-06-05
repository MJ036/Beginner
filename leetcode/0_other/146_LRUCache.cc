#include "mai.h"
#include <algorithm>
#include <iomanip>
#include <random>
#include <string>
#include <sys/types.h>
#include <type_traits>
#include <unordered_map>

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

class LRUCache2 {
private:
    //逻辑删除链表节点
    void remove(Node* x){
        x->prev->next = x->next;
        x->next->prev = x->prev;
    }

    //把一个节点放到表头
    void push_front(Node* x){
        //先接入x
        x->prev = _dummy;
        x->next = _dummy->next;
        //再更新x临近节点
        _dummy->next->prev = x;
        _dummy->next = x;

    }

    //获取key对应的节点，同时把节点放到链表头部
    Node* get_node(int key){
        auto it = _keyToNode.find(key);
        if(it == _keyToNode.end()){
            return nullptr;
        }
        Node* node = it->second;
        remove(node);
        push_front(node);
        return node;
    }

public:
    LRUCache2(int capacity)
        :_capacity(capacity)
         ,_dummy(new Node())
    {
        _dummy->prev = _dummy;
        _dummy->next = _dummy;

    }

    int get(int key) {
        Node* node = get_node(key);
        return node ? node->value : -1;
    }

    //使用过的才放进去，所以put的元素应该在首部
    void put(int key, int value) {
        Node* node = get_node(key);
        if(node){
            node->value = value;
            return;
        }
        auto new_node = new Node(key,value);
        push_front(new_node);
        _keyToNode[key] = new_node;


        //如果链表满了，移除最后一个
        if(_capacity < _keyToNode.size()){
            Node* back_node = _dummy->prev;
            _keyToNode.erase(back_node->key);
            remove(back_node);
            delete back_node;
        }
    }
private:
    int _capacity;
    Node* _dummy;
    unordered_map<int,Node*> _keyToNode;
};


class LRUCache3 {
private:
    void remove(Node* n){
        n->prev->next = n->next;
        n->next->prev = n->prev;
    }

    void push_front(Node* n){
        n->next = _dummy->next;
        n->prev = _dummy;
        _dummy->next->prev = n;
        _dummy->next = n;
    }
    Node* get_node(int key){
        auto it = _keyToNode.find(key);
        if(it == _keyToNode.end()){
            return nullptr;
        }

        auto node = it->second;
        remove(node);
        push_front(node);
        return node;

    }
public:
    LRUCache3(int capacity) 
    :_capacity(capacity)
     ,_dummy(new Node())
    {
        _dummy->next = _dummy;
        _dummy->prev = _dummy;
    }
    
    int get(int key) {
        //获取节点，若存在放在表头
        auto node = get_node(key);
        return node ? node->value : -1;
    }
    
    void put(int key, int value) {
        auto n = get_node(key);
        if(n){
            n->value = value;
            return;
        }
        //节点不存在,插入
        auto node = new Node(key,value);
        _keyToNode[key] = node;
        push_front(node);
        if(_keyToNode.size() > _capacity){
            auto back_node = _dummy->prev;
            _keyToNode.erase(back_node->key);
            remove(back_node);
            delete back_node;
        }
        
    }
private:
    int _capacity;
    Node* _dummy;
    int key;
    int value;
    unordered_map<int,Node*> _keyToNode;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
