#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#define SWAP(arr,i,j) {\
    int tmp = arr[i];        \
    arr[i] = arr[j];    \
    arr[j] = tmp;       \
}

void print_arr(int arr[],int left,int right){
    for(int i = left; i <= right; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int partition(int arr[],int left,int right){
    int pivot_idx = left + rand() % (right - left + 1);
    int pivot = arr[pivot_idx];
    SWAP(arr,pivot_idx,right);

    int partition_idx = left;

    for(int i = left ; i < right ;++i){
        if(arr[i] < pivot){
            SWAP(arr,i,partition_idx);
            ++partition_idx;
        }
    }
    SWAP(arr,right,partition_idx);

    printf("pivot of this round is %d\n arr is:",pivot);
    print_arr(arr,left,right);

    return partition_idx;
}

void partition_recursion(int arr[],int left,int right){
    if(left >= right){
        return;
    }
    int idx = partition(arr,left,right);
    partition_recursion(arr,left,idx - 1);
    partition_recursion(arr,idx + 1,right);

}

void quick_sort_one_way(int arr[],int len){
    srand(time(NULL));
    partition_recursion(arr,0,len-1);
}


int main()
{
    int arr[] = { 8,3,2,6,9,5 };
    /* partition(arr,0,5); */
    /* printf("%ld",sizeof(arr)/sizeof(arr[0])); */
    quick_sort_one_way(arr,sizeof(arr)/sizeof(arr[0]));
    print_arr(arr,0,5);

    return 0;
}

