#include<bits/stdc++.h>
using namespace std;

/**
 * 
 * Use Max heap for sorting
 * Max Heap Property :
 * Each subtree ensures that root is greater than both the child.
 * 
**/

// heapify the array
void heapify(int a[], int n, int index){
    int largest = index;
    int left = 2*index+1; //left child 
    int right = 2*index+2; //right child

    if(left<n && a[left] > a[largest]) //check if left child is larger than root
        largest = left;
    if(right < n && a[right] > a[largest]) //check if right child is larger than root or left
        largest = right;                   //largest will become left child by now if left > root

    if(largest != index){
        swap(a[index], a[largest]);
        heapify(a,n, largest);
    }
}

// build max heap
void buildHeap(int a[], int n){
    // leaf nodes ensures max heap property
    // all non leaf nodes are one level up which would be (n/2)-1
    int startIndex = (n/2)-1;
    for(int index=startIndex; index>=0;index--){
        heapify(a, n, index);
    }
}


int deleteRoot(int a[], int n){

    // exchange root with last element and then delete last element
    // then heapify
    swap(a[0], a[n-1]);
    int x = a[n-1];
    heapify(a, n-1, 0); //heapify from root only
    return x;
}

// descending order sort
void sort(int a[], int n){
    int i;

    printf("Sorted Array : \n");
    for(i=0;i<n;i++){
        printf("%d ", deleteRoot(a, n-i));
    }    
    printf("\n");

}

void printHeap(int a[], int n){
    int i;
    for(i=0;i<n;i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}
int main(){
    int n, i;
    scanf("%d", &n);
    
    int a[n];
    
    for(i=0;i<n;i++){
        scanf("%d", &a[i]);
    }

    printf("Initial Heap : \n");
    printHeap(a,n);
    
    buildHeap(a, n);

    printf("Max Heap : \n");
    printHeap(a,n);

    sort(a, n);
}