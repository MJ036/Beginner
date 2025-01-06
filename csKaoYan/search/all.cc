#include "mai.h"

using namespace std;

void swap(int* arr, int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
void print_arr(int* arr, int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
}

void select_sort(int* arr, int n){
    for(int i = 0; i < n - 1; i++){
        int min = i;
        for(int j = i + 1; j < n; j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }
        swap(arr,min,i);
    }
}

//can end early
//Essence: traverse the unsorted region
void bubble_sort(int* arr, int n){
    bool flag;
    for(int i = 0; i < n - 1 ; ++i){
        flag = true;
        for(int j = 0; j < n - i - 1; ++j){
            if(arr[j] > arr[j+1]){
                swap(arr, j, j+1);
                flag = false;
            }
        }
        if(flag){
            return;
        }
    }
}

//Simple direct insertion sort
void insert_sort(int* arr, int n){
    // i: The index of the element to be inserted
    for(int i = 1; i < n; ++i){
        int value = arr[i];
        int j = i - 1;
        while(j >=0 && value < arr[j]){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = value;
    }
}

//compared to simple insertion sort,shell can reduce the number of long-distance exchanges
//Intergroup insertion sort
void shell_sort(int* arr, int n){
    int gap = n >> 1;   //gap : interval
    while(gap){
        for(int i = gap; i < n; ++i){
            int value = arr[i];
            int j = i - gap;
            while(j >= 0 && value < arr[j]){
                arr[j + gap] = arr[j];
                j -= gap;
            }
            arr[j+gap] = value;
        }
        gap >>= 1; 
    }
}

int partition(int* arr, int left, int right){
    int pivot = arr[left];
    int i = left, j = right;
    while(i < j){
        while(i < j  && arr[j] >= pivot){
            j--;
        }
        arr[i] = arr[j];
        
        while(i < j && arr[i] <= pivot){
            i++;
        }
        arr[j] = arr[i];
    }//i == j
    arr[i] = pivot;
    return i;
}
void q_sort(int* arr,int left, int right){
    if(left >= right){
        return;
    }
    int idx = partition(arr,left,right);
    q_sort(arr,0,idx - 1);
    q_sort(arr,idx + 1, right);
}
void quickSort(int* arr,int n){
    q_sort(arr,0,n-1);
}

#define N 7
int temp[N];
void merge(int* arr,int left,int mid, int right){
    int i = left, j = mid + 1,k = left;
    while(i <= mid && j <= right){
        if(arr[i] <= arr[j]){
            temp[k++] = arr[i++];
        }else{
            temp[k++] = arr[j++];
        }
    }
    while(i <= mid){
        temp[k++] = arr[i++];
    }
    while(j <= right){
        temp[k++] = arr[j++];
    }
    for(int k = left; k <= right;k++){
        arr[k] = temp[k];
    }

}
void m_sort(int* arr, int left ,int right){
    if(left >= right) return;
    int mid = left + ((right - left) >> 1);
    m_sort(arr,left,mid);
    m_sort(arr,mid + 1, right);
    merge(arr,left,mid,right);

}
void mergeSort(int* arr, int n){
   m_sort(arr,0,n - 1); 

}


void heapify(int* arr, int i, int n){
    while(i < n){
        int maxIdx = i;
        int left = i*2 + 1;
        int right = i*2 + 2;

        if(left < n && arr[left] > arr[maxIdx]){
            maxIdx = left;
        }
        if(right < n && arr[right] > arr[maxIdx]){
            maxIdx = right;
        }
        if(maxIdx == i) break;

        swap(arr,i,maxIdx);
        i = maxIdx;
    }
}
void buildHeap(int* arr, int n){
    for(int i = (n - 2)  >> 1; i >= 0; i--){
        heapify(arr,i,n);
    }
}

void heapSort(int* arr,int n){
    buildHeap(arr,n);
    int len = n;
    while(len > 1){
        swap(arr,0,len - 1);
        len--;
        heapify(arr,0,len);
    }
    
}



int main()
{
    int arr[] = {1,9,4,2,7,4,3};
    //select_sort(arr,SIZE(arr));
    //insert_sort(arr,SIZE(arr));
    //shell_sort(arr,SIZE(arr));
    //bubble_sort(arr,SIZE(arr));
    //quickSort(arr,SIZE(arr));
    //mergeSort(arr,SIZE(arr));
    heapSort(arr,SIZE(arr));

    print_arr(arr,SIZE(arr));
    cout << endl;

    return 0;
}

