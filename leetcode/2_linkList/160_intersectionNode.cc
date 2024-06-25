#include <utility>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *curA = headA;
        ListNode *curB = headB;
        int lenA = 0;
        int lenB = 0;
        while(curA != nullptr){
            lenA++;
            curA = curA->next;
        }
        while(curB != nullptr){
            lenB++;
            curB = curB->next;
        }
        curA = headA;
        curB = headB;
        if(lenB > lenA){
            swap(lenA,lenB);
            swap(curA,curB);
        }
        int gap = lenA - lenB;
        while(gap--){
            curA = curA->next;
        }
        while(curA != curB && curA != nullptr){
            curA = curA->next;
            curB = curB->next;
        }
        if(curA == curB){
           return curA;
        }else{
            return nullptr;
        }
    }
};
