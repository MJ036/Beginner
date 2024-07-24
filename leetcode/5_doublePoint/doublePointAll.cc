#include "mai.h"

using namespace std;


int removeElement(vector<int>& nums, int val) {
    int slow = 0;
    for(size_t fast = 0; fast <nums.size(); fast++){
        while(nums[fast] != val){
            nums[slow++] = nums[fast++]; 
        }
    }
    return slow;

}

void reverseString(vector<char>& s) {
    for(size_t i = 0, j = s.size()-1; i < s.size()/2; i++,j--){
        swap(s[i],s[j]);
    }
}

string replaceSpace(string s){
    int count = 0;
    int sOldSize = s.size();
    for(size_t i = 0; i < s.size(); ++i){
        if(s[i] == ' '){
            count++;
        }
    }
    s.resize(sOldSize + 2*count);
    int sNewSize = s.size();
    for(int i = sNewSize - 1,j = sOldSize - 1; j < i; --i,--j){
        if(s[j] != ' '){
            s[i--] = s[j--];
        }else{
            s[i] = '0';
            s[i-1] = '2';
            s[i-2] = '%';
            i -= 2;
        }
    }
    return s;
}

//4
void reverse(string s,int start,int end){
    for(size_t i = start, j = end; i < j; ++i,--j){
        swap(s[i],s[j]);
    }
}

void removeExtraSpace(string &s){
    int slow = 0;
    for(size_t i = 0; i < s.size(); i++){
        if(s[i] != ' '){
            if(slow != 0) s[slow++] = ' ';
            while(i < s.size() && s[i] != ' '){
                s[slow++] = s[i++];
            }
        }
    }
    s.resize(slow);
}

string reverseWords(string s){
    removeExtraSpace(s);
    reverse(s,0,s.size()-1);
    int start = 0;
    for(size_t i = 0; i < s.size(); ++i){
        if(i == s.size() || s[i] == ' '){
            reverse(s,start,i - 1);
            start = i + 1;
        }
    }
    return s;
}

//5

struct ListNode{
    ListNode(int value):val(value){}
    int val;
    ListNode *next;
};


ListNode* reverseList(ListNode* head){
    ListNode* temp = nullptr;
    ListNode* pre = nullptr;
    ListNode* cur = head;
    while(cur){
        temp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = temp;
    }
    return pre;
}

//6
ListNode * removeNthFromEnd(ListNode* head, int n){
    ListNode *dummyHead = new ListNode(0);
    dummyHead->next = head;
    ListNode *slow = dummyHead , *fast = dummyHead;
    fast = fast->next;
    while(n-- && fast != nullptr){
        fast = fast->next;
    }

    while(fast != nullptr){
        slow = slow->next;
        fast = fast->next;
    }

     ListNode *temp = slow->next;
    slow->next = temp->next;
    delete temp;

    return dummyHead->next;

}

//7

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB){
    int lenA = 0,lenB = 0;
    ListNode *curA = headA;
    ListNode *curB = headB;
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
    
    if(lenA < lenB){
        swap(lenA,lenB);
    }
    int gap = lenA - lenB;
    while(gap--){
        curA = curA->next;
    }
    while(curA != nullptr){
        if(curA == curB){
            return curA;
        }
        curA = curA->next;
        curB = curB->next;
    }
    return nullptr;
    
}

//8
ListNode *detectCycle(ListNode *head){
    ListNode* fast = head;
    ListNode* slow = head;
    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow){
            ListNode* idx1 = fast;
            ListNode* idx2 = head;
            while(fast != head){
                fast = fast->next;
                slow = slow->next;
            }
            return fast;
        }
    }
    return nullptr;
}

//9
vector<vector<int>> threeSum(vector<int>& nums){
    vector<vector<int>> result;
    sort(nums.begin(),nums.end());
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] > 0){
            return result;
        }
        if(i > 0 && nums[i] == nums[i-1]){
            continue;
        }
        int left = i+1;
        int right = nums.size() - 1;
        while(right > left){
            if(nums[i] + nums[left] + nums[right] > 0) right--;
            else if(nums[i] + nums[left] + nums[right] < 0) left++;
            else{
                result.push_back(vector<int>{nums[i], nums[left],nums[right]});
                while(right > left && nums[right] == nums[right - 1]) right--;
                while(right > left && nums[left] == nums[left +1]) left++;
                right--;
                left++;
            }
        }
    }
    return result;
}

//10

vector<vector<int>> fourSum(vector<int>&nums,int target){
    vector<vector<int>> result;
    sort(nums.begin(),nums.end());
    for(int k = 0; k < nums.size(); k++){
        if(nums[k] >= 0 && nums[k] > target){
            break;
        }
        if(nums[k] == nums[k-1] && k > 0){
            continue;
        }
        for(int i = k+1; i < nums.size(); i++){
            if(nums[k] + nums[i] > target && nums[k]+ nums[i] >= 0){
                break;
            }
            if(i > k+1 && nums[i] == nums[i-1]){
                continue;
            }
            int left = i+1;
            int right = nums.size()-1;
            while(left < right){
                if((long)nums[k] + nums[i] +nums[left] + nums[right] > target) right--;
                else if((long)nums[k] + nums[i] +nums[left] + nums[right] < target) left++;
                else{
                    result.push_back(vector<int>{nums[k], nums[i], nums[left], nums[right]});
                    while(left < right && nums[left] == nums[left+1]) left++;
                    while(left < right && nums[right] == nums[right-1]) right--; 
                    left++;
                    right--;
                }
            }
        }
    }
    return result;
}

