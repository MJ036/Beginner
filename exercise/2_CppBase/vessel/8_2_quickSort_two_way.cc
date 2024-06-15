#include <iostream>
#include <stdio.h>

using namespace std;

void print_arr(int arr[],int left,int right){
    for(int i = left; i <= right; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int partition(int arr[],int left,int right){
    int pivot = arr[left];
    
    int low = left,high = right;
    while(low < high){
        while(low < high && arr[high] >= pivot){
            --high;
        }
        arr[low] = arr[high];
        while(low < high && arr[low] < pivot){
            ++low;
        }
        arr[high] = arr[low];
    }
    arr[low] = pivot;

    return low;
}

void partition_recursion(int arr[],int left,int right){
    if(left >= right){
        return;
    }
    int idx = partition(arr,left,right);
    partition_recursion(arr,left,idx - 1);
    partition_recursion(arr,idx + 1,right);
}

void quick_two_way(int arr[],int len){
    partition_recursion(arr,0,len - 1);
}


int main()
{
    int arr[] = { 8,3,2,6,9,5 };
    quick_two_way(arr,sizeof(arr)/sizeof(arr[0]));
    print_arr(arr,0,sizeof(arr)/sizeof(arr[0])-1);
    return 0;
}

