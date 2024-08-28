#include "mai.h"

using  ElemType = int;
#define InitSize 100

typedef struct{
    ElemType *data;
    int length;
    int MaxSize;
}seqList;

void InitList(seqList &L){
    L.data = (ElemType *)malloc(sizeof(ElemType*)*InitSize);
    L.length = 0;
    L.MaxSize = InitSize;
}

bool ListInsert(seqList &L, int i , ElemType e){
    for(int j = L.length; j >= i; j--){
        L.data[j] = L.data[j-1];
    }
    L.data[i-1] = e;
    L.length++;
    return true;
}

bool ListDelete(seqList &L, int i, ElemType &e){
    e = L.data[i-1];
    for(int j = i; j < L.length; j++){
        L.data[j-1] = L.data[j];
    }
    L.length--;
    return true;
}





void test_04(seqList &L,int s, int t){
    int slow = 0,fast;
    for(fast = 0; fast < L.length; fast++){
        if(s <= L.data[fast] && L.data[fast] >= t){
            continue;
        }
        L.data[slow++] = L.data[fast];
    }
    L.length = slow + 1;


}

using namespace std;

int main()
{

    return 0;
}

