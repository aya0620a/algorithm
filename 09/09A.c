#include <stdio.h>

#define MAX 10000

int parent(int i){
    return i/2;
}

int left(int i){
    return 2*i;
}

int right(int i){
    return 2*i+1;
}

void printNode(int i, int A[], int sizeofHeap){
    printf("node %d: key = %d, ", i, A[i]);
    if(parent(i) >= 1){
        printf("parent key = %d, ", A[parent(i)]);
    }
    if(left(i) <= sizeofHeap){
        printf("left key = %d, ", A[left(i)]);
    }
    if(right(i) <= sizeofHeap){
        printf("right key = %d, ", A[right(i)]);
    }
    printf("\n");
}

int main (void){
    int sizeofHeap;

    scanf("%d", &sizeofHeap);

    int A[MAX+1];

    
    for(int i = 0; i < sizeofHeap; i++){
        scanf("%d", &A[i+1]);
    }

    for(int i = 1; i <= sizeofHeap; i++){
        printNode(i, A, sizeofHeap);
    }
    
    return 0;
}