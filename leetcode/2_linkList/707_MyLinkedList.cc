#include <iostream>
#include <vector>

using namespace std;

class MyLinkedList{
public:
    struct LinkedNode{
        int val;
        LinkedNode *next;
        LinkedNode(int val) : val(val),next(nullptr){}
    };

    MyLinkedList(){
        _dummyHead = new LinkedNode(0);
        _size = 0;
    }

    int get(int index){
        if(index > (_size - 1) || index < 0){
            return -1;
        }
        LinkedNode *cur = _dummyHead->next;
        while(index--){
            cur = cur->next;
        }
        return cur->val;
    };

    void addAtHead(int val){
        LinkedNode *temp = new LinkedNode (val);
        temp->next = _dummyHead->next;
        _dummyHead->next = temp;
        _size++;
    }

    void addAtTail(int val){
        LinkedNode *temp = _dummyHead;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = new LinkedNode(val);
        _size++;
    }

    void addAtIndex(int index,int val){
        if(index > _size) return;
        if(index < 0) index = 0;
        LinkedNode *before = _dummyHead;
        LinkedNode *newNode = new LinkedNode(val); 
        while(index--){
            before = before->next;          
        }
        newNode->next = before->next;
        before->next = newNode;
        _size++;

    }

    void deleteAtIndex(int index){
        if(index > (_size - 1) || index < 0){
            return;
        }
        LinkedNode *cur = _dummyHead;
        while(index--){
            cur = cur->next;
        }
        LinkedNode *temp = cur->next;
        cur->next = cur->next->next;
        delete temp;
        temp = nullptr;
        _size--;
    }

    void printLinkedList(){
        LinkedNode* cur = _dummyHead;
        while(cur->next != nullptr){
            cout << cur->next->val << " ";
            cur = cur->next;
        }
        cout << endl;

    }


private:
    int _size;
    LinkedNode *_dummyHead;
};


