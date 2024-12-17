#include "mai.h"
typedef struct Node{
    int data;
    struct Node* next;
}Node;

//头插法链表实现栈
typedef struct Stack{
    Node* head;
    int size;
}Stack;

Stack* Init_Stack();
void Destory_Stack(Stack* st);
bool Empty(Stack *st);
void push(Stack *st, int val);
int pop(Stack *st);
int peek(Stack *st);
    
Stack* Init_Stack(){
	Stack* ret =  (Stack*)malloc(sizeof(Stack));
    ret->size = 0;
    ret->head = NULL;
    return ret;
}

void Destory_Stack(Stack* st){
    Node *temp, *cur = st->head;
    while(cur != NULL){
        temp = cur;
        cur = cur->next;
        free(temp);
    }
    free(st);
}

bool Empty(Stack *st){
    return !st->size;
}

void push(Stack *st, int val){
	Node* newNode = (Node*)malloc(sizeof(Node));
	
	newNode->data = val;

	newNode->next = st->head;
	st->head = newNode;

	st->size++;
}
int pop(Stack *st){
    if(Empty(st)){
        return 0;
    }
    int val = st->head->data;
    Node* temp = st->head;
    st->head = temp->next;
    free(temp);
    return val;
}

int peek(Stack *st){
    if(!Empty(st)){
        return st->head->data;
    }
    return 0;
}

int main(){
    Stack *st = Init_Stack();
    push(st,1);
    push(st,2);
    std::cout << "2:" <<  peek(st) << std::endl;
    push(st,3);
    push(st,4);
    push(st,5);
    std::cout << "5:" <<  peek(st) << std::endl;

    std::cout <<"pop:" <<  pop(st) << std::endl;;
    std::cout <<"peek:" <<  peek(st) << std::endl;;
    Destory_Stack(st);

}
