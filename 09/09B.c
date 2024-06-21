#include <stdio.h>

#define MAX 1000000

void maxHeapify(int i, int A[], int sizeofHeap){
    int left = 2*i;
    int right = 2*i+1;
    int largest;

    if(left <= sizeofHeap && A[left] > A[i]){
        largest = left;
    }
    else{
        largest = i;
    }

    if(right <= sizeofHeap && A[right] > A[largest]){
        largest = right;
    }

    if(largest != i){
        int tmp = A[i];
        A[i] = A[largest];
        A[largest] = tmp;
        maxHeapify(largest, A, sizeofHeap); //再帰呼び出し
    }
}



int main(void){
    int sizeofHeap;
    
    scanf("%d", &sizeofHeap);

    int A[MAX+1];

    for(int i = 0; i < sizeofHeap; i++){
        scanf("%d", &A[i+1]);
    }

    for(int i = sizeofHeap/2; i >= 1; i--){
        maxHeapify(i, A, sizeofHeap);
    }

    for(int i = 1; i <= sizeofHeap; i++){
        printf(" %d", A[i]);
    }

    printf("\n");

    return 0;
}