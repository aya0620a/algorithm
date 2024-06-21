#include <stdio.h>

void printArray(int n, int A[][n]){
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){

            if(j != 0){
                printf(" ");
            }

            if(A[i][j] == 1){
                printf("%d", A[i][j]);
                // printf(" %d", 1);
            }
            else{
                printf("%d", 0);
                // printf(" %d", 0);
            }
        }
        if(i != n-1){
            printf("\n");
        }
    }
    
}

int main (void){
    int node_num; //頂点数n
    int u, k; //頂点uの出次数k

    scanf("%d", &node_num);

    int A[node_num][node_num]; //隣接行列
    int V[node_num]; //頂点uの訪問状態

    for (int i = 0; i < node_num; i++) {
        for (int j = 0; j < node_num; j++) {
            A[i][j] = 0;
        }
    }


    for(int i = 0; i < node_num; i++){
        scanf("%d %d", &u, &k);

        for(int j = 0; j < k; j++){
            scanf("%d", &V[j]);
            
            A[u-1][V[j]-1] = 1;
        }
    }

    printArray(node_num, A);

    printf("\n");

    return 0;
}