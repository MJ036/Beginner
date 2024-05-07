#include <iostream>

using namespace std;

class Stack
{
public:

    Stack(int size = 10)
        :_size(size)
         ,_top(-1)
         ,_data(new int[_size]())
    {}

    ~Stack(){
        if(_data)
        {
            delete[]_data;
            _data = nullptr;
        }            
    }


    bool empty();
    bool full();
    void push(int);
    void pop();
    int top();

private:
    int _size;
    int _top;
    int *_data;
};

bool Stack::empty(){
    return _top == -1;
}

bool Stack::full(){
    return _top == _size -1;
}

void Stack::push(int value){
    if(!full()){
        _data[++_top] = value;
    }
    else{
        cout << "The Stack is full" << endl;
    }
}

void Stack::pop(){
    if(!empty()){
        --_top;
    }
    else{
        cout << "The Stack is empty" << endl;
    }
}

int Stack::top(){
    return _data[_top];
}
void test(){
    Stack stk;
    cout << stk.empty() << endl;
    stk.push(10);
    cout << stk.empty() << endl;
    cout << stk.top() << endl;
    stk.pop();
    cout << stk.empty() << endl;
    stk.push(10);
    stk.push(10);
    stk.push(10);
    stk.push(10);
    stk.push(10);
    stk.push(10);
    stk.push(10);
    stk.push(10);
    stk.push(10);
    stk.push(10);
    cout << stk.full() << endl;
}

int main()
{
    test();
    return 0;
}

