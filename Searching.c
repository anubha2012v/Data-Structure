#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int A[10];
    int size;
    int length;
};

void swap(int *x,int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void Display(struct Array arr){
    int i;
    printf("Elements are: \n");
    for(i=0; i<arr.length; i++){
        printf("%d ", arr.A[i]);
    }
}

//Simple LinearSearch
int LinearSearch(struct Array arr,int key){
    int i;
    for(i=0;i< arr.length;i++){
        if(key ==arr.A[i])
            return i;
    }
    return -1;
}

//Improved Linear Search
int LinearSearch1(struct Array *arr,int key){
    int i;
    for(i=0;i<arr->length;i++){
        if(key ==arr->A[i]){
            swap(&arr->A[i], &arr->A[i-1]);
            return i;
        }
    }
    return -1;
}

//Binary Search
int BinarySearch(struct Array arr,int key){
    int l,mid,h;
    l = 0;
    h = arr.length - 1;

    while(l < h){
        mid = (l + h)/2;
        if(key == arr.A[mid])
            return mid;
        else if(key < arr.A[mid])
            return h = mid - 1;
        else
            return l = mid + 1;
    }
    return -1;
}

//Recursive Binary search
int RBinarySearch1(int a[],int l, int h, int key){
    int mid;

    if(l <= h){
        mid = (l+h)/2;
        if(key == a[mid])
            return mid;
        else if(key < a[mid])
            return RBinarySearch1(a,l,mid-1,key);
        else
            return RBinarySearch1(a,mid+1,h,key);
    }
    return -1;
}
int main(){

    struct Array arr = {{2,3,4,5,6,7,8,14},10,8};
    Display(arr);
    

    printf("\nKey is at Index: %d\n", LinearSearch(arr,5));
    printf("\nKey is at Index: %d\n", LinearSearch1(&arr,4));
    printf("\nKey is at Index: %d\n", BinarySearch(arr,6));
    printf("\nKey is at Index: %d\n", RBinarySearch1(arr.A,0,arr.length,7));
    return 0;
}
