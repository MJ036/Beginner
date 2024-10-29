#include <vector>
#include <iostream>

using namespace std;

void test(){
    vector<int> nums {1,2,3,4};
    vector<int> nums2 {2,6,8,0};

    vector<vector<int>> vecs{nums,nums2};

    for(auto & vec : vecs){
        for(auto & ele : vec){
            cout << ele << " ";
        }
        cout << endl;
    }
    
    cout << "&nums:" << &nums << endl;
    cout << "&nums[0]" << &nums[0] << endl;
    
    cout << "&vecs:" << &vecs << endl;
    cout << "&vecs[0]" << &vecs[0] << endl;
    cout << "&vecs[1]" << &vecs[1] << endl;

    cout << &vecs[0][0] << endl;
    cout << &vecs[0][1] << endl;
}

int main()
{
    test();
    return 0;
}

