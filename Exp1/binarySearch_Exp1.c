#include <stdio.h>
#include <stdlib.h>

int binarySearch(int *arr , int key , int start , int end) {
    
    if(start>end) {
        return -1 ;
    }
    
    int mid = start + (end-start)/2 ; 
    
    if(*(arr+mid) == key) {
        return mid ; 
    }
    
    else if(*(arr+mid) > key) {
        return binarySearch(arr , key , start , mid-1) ;
    }
    
    else {
        return binarySearch(arr, key ,mid+1 , end);
    }
}


int main()
{
    int n ; 
    printf("Enter the number of elements : ");
    scanf("%d",&n);
    
    int *ptr = (int*)calloc(n , sizeof(int));
    printf("Enter the elements in the array : \n");
    for(int i = 0 ; i < n ; i++ ) {
        scanf("%d",ptr+i);
    }
    
    printf("Enter the key to be searched : ");
    int key ; 
    scanf("%d",&key);
    
    int index = binarySearch(ptr,key,0,n-1);
    printf("Key value at index %d",index);

    free(ptr);

    return 0;
}

