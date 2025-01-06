#include "mai.h"

using namespace std;
int search1(int* arr,int left, int right, int key){
    if(left > right) return -1;
    int mid = left + ((right - left) >> 1);
    int cmp = arr[mid]- key;
    if(cmp < 0){
        return search1(arr,mid + 1,right,key);
    }else if(cmp > 0){
        return search1(arr,left,mid -1,key);
    }else{
        return mid;
    }
}
//iteration
int search2(int* arr,int n, int key){
    int left =0, right = n - 1;
    while(left <= right){
        int mid = left + ((right - left) >> 1);
        int cmp = arr[mid]- key;
        if(cmp > 0){
            right = mid - 1;
        }else if(cmp < 0){
            left = mid + 1;
        }else{
            return mid;
        }
    }
    return -1;
}

//variant based on iteration
//find first one that equal to key
int search3(int* arr,int left, int right, int key){
    while(left <= right){
        int mid = left + ((right - left) >> 1);
        int cmp = arr[mid]- key;
        if(cmp > 0){
            right = mid - 1;
        }else if(cmp < 0){
            left = mid + 1;
        }else{
            if(mid == left || arr[mid - 1] < key){
                return mid;
            }
            right = mid - 1;
        }
    }
    return -1;
}
//find first one that big and equal to key
int search4(int* arr,int left, int right, int key){
    while(left <= right){
        int mid = left + ((right - left) >> 1);
        int cmp = arr[mid]- key;
        if(cmp < 0){
            left = mid + 1;
        }else{
            if(mid == left || arr[mid - 1] < key){
                return mid;
            }
            right = mid - 1;
        }
    }
    return -1;
}
//find last one that equal key
int search5(int* arr,int left, int right, int key){
    while(left <= right){
        int mid = left + ((right - left) >> 1);
        int cmp = arr[mid]- key;
        if(cmp > 0){
            right = mid - 1;
        }else if(cmp < 0){
            left = mid + 1;
        }else{
            if(mid == right || arr[mid + 1] > key){
                return mid;
            }
            left = mid + 1;
        }
    }
    return -1;
}
//find last one that small and equal key
int search6(int* arr,int left, int right, int key){
    while(left <= right){
        int mid = left + ((right - left) >> 1);
        int cmp = arr[mid]- key;
        if(cmp > 0){
            right = mid - 1;
        }else{
            if(mid == right || arr[mid + 1] > key){
                return mid;
            }
            left = mid + 1;
        }
    }
    return -1;
}


int search(int* arr,int n,int key){
    //recursive
    return search2(arr,n,key);

}

int main()
{
    int arr[] = {1,4,7,9,14,26,115,119,300,500,700};
    cout << search(arr,SIZE(arr),1) << endl;
    cout << search(arr,SIZE(arr),9) << endl;
    cout << search(arr,SIZE(arr),10) << endl;

    return 0;
}

